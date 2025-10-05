/* mini_http_cache_server.c
 *
 * Single-file complex C program:
 * - Non-blocking TCP accept + poll() event loop
 * - Thread pool (fixed worker threads)
 * - Simple HTTP/1.0 GET handling
 * - In-memory LRU cache for file contents (configurable max bytes)
 * - Tiny memory arena for per-request allocations
 * - Minimal MIME type detection
 *
 * Compile:
 *   gcc -O2 -pthread mini_http_cache_server.c -o mini_http_cache_server
 *
 * Run:
 *   ./mini_http_cache_server <port> <www-root> <cache-bytes>
 *
 * Example:
 *   ./mini_http_cache_server 8080 ./www 50_000_000
 */

#define _GNU_SOURCE
#include <arpa/inet.h>
#include <errno.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <poll.h>
#include <pthread.h>
#include <signal.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>

/*** Configuration ***/
#define MAX_EVENTS 1024
#define BACKLOG 128
#define WORKER_THREADS 8
#define REQ_BUF_SIZE 8192
#define CACHE_BUCKETS 4096

/*** Utilities ***/
static void die(const char *fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    vfprintf(stderr, fmt, ap);
    va_end(ap);
    exit(EXIT_FAILURE);
}

static int set_nonblocking(int fd) {
    int flags = fcntl(fd, F_GETFL, 0);
    if (flags == -1) return -1;
    return fcntl(fd, F_SETFL, flags | O_NONBLOCK);
}

static char *now_str() {
    static __thread char buf[64];
    time_t t = time(NULL);
    struct tm tm;
    localtime_r(&t, &tm);
    strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", &tm);
    return buf;
}

static void log_info(const char *fmt, ...) {
    va_list ap; va_start(ap, fmt);
    fprintf(stderr, "[%s] INFO: ", now_str());
    vfprintf(stderr, fmt, ap);
    fprintf(stderr, "\n");
    va_end(ap);
}

static void log_err(const char *fmt, ...) {
    va_list ap; va_start(ap, fmt);
    fprintf(stderr, "[%s] ERROR: ", now_str());
    vfprintf(stderr, fmt, ap);
    fprintf(stderr, "\n");
    va_end(ap);
}

/*** Simple memory arena for per-request allocations ***/
typedef struct {
    char *buf;
    size_t cap;
    size_t used;
} arena_t;

static void arena_init(arena_t *a, size_t cap) {
    a->buf = malloc(cap);
    a->cap = cap;
    a->used = 0;
}

static void arena_free(arena_t *a) {
    free(a->buf);
    a->buf = NULL;
    a->cap = 0;
    a->used = 0;
}

static void *arena_alloc(arena_t *a, size_t n) {
    if (a->used + n > a->cap) return NULL;
    void *p = a->buf + a->used;
    a->used += n;
    return p;
}

/*** LRU cache implementation for file contents ***/

typedef struct cache_entry {
    // key -> filepath strdup'ed
    char *key;
    void *data;
    size_t size;
    // doubly-linked list pointers for LRU
    struct cache_entry *prev, *next;
    struct cache_entry *hash_next; // chaining in hash bucket
    uint64_t last_access; // monotonic counter
} cache_entry_t;

typedef struct {
    cache_entry_t **buckets;
    size_t nbuckets;
    cache_entry_t *head; // most recently used
    cache_entry_t *tail; // least recently used
    size_t total_bytes;
    size_t max_bytes;
    pthread_mutex_t lock;
    uint64_t tick;
} cache_t;

static uint64_t hash_fn(const char *s) {
    // simple FNV-1a 64-bit
    uint64_t h = 1469598103934665603ULL;
    while (*s) {
        h ^= (unsigned char)*s++;
        h *= 1099511628211ULL;
    }
    return h;
}

static cache_t *cache_create(size_t nbuckets, size_t max_bytes) {
    cache_t *c = calloc(1, sizeof(cache_t));
    c->buckets = calloc(nbuckets, sizeof(cache_entry_t *));
    c->nbuckets = nbuckets;
    c->max_bytes = max_bytes;
    pthread_mutex_init(&c->lock, NULL);
    c->head = c->tail = NULL;
    c->total_bytes = 0;
    c->tick = 1;
    return c;
}

static void cache_evict_one(cache_t *c) {
    // Remove tail (least recently used)
    if (!c->tail) return;
    cache_entry_t *e = c->tail;
    // unlink from LRU list
    if (e->prev) e->prev->next = NULL;
    c->tail = e->prev;
    if (!c->tail) c->head = NULL;
    // remove from hash bucket
    uint64_t h = hash_fn(e->key) % c->nbuckets;
    cache_entry_t *cur = c->buckets[h], *prev = NULL;
    while (cur) {
        if (cur == e) {
            if (prev) prev->hash_next = cur->hash_next;
            else c->buckets[h] = cur->hash_next;
            break;
        }
        prev = cur;
        cur = cur->hash_next;
    }
    c->total_bytes -= e->size;
    free(e->data);
    free(e->key);
    free(e);
}

static void cache_touch(cache_t *c, cache_entry_t *e) {
    // move to head (most recently used)
    if (c->head == e) return;
    // unlink
    if (e->prev) e->prev->next = e->next;
    if (e->next) e->next->prev = e->prev;
    if (c->tail == e) c->tail = e->prev;
    // put at head
    e->prev = NULL;
    e->next = c->head;
    if (c->head) c->head->prev = e;
    c->head = e;
    if (!c->tail) c->tail = e;
    e->last_access = ++c->tick;
}

static cache_entry_t *cache_lookup_locked(cache_t *c, const char *key) {
    uint64_t h = hash_fn(key) % c->nbuckets;
    cache_entry_t *e = c->buckets[h];
    while (e) {
        if (strcmp(e->key, key) == 0) {
            cache_touch(c, e);
            return e;
        }
        e = e->hash_next;
    }
    return NULL;
}

static void cache_put_locked(cache_t *c, const char *key, void *data, size_t size) {
    if (size > c->max_bytes) {
        // Too big to cache
        free(data);
        return;
    }
    // evict until there's room
    while (c->total_bytes + size > c->max_bytes) {
        cache_evict_one(c);
    }
    cache_entry_t *e = malloc(sizeof(cache_entry_t));
    e->key = strdup(key);
    e->data = data;
    e->size = size;
    e->prev = NULL; e->next = c->head;
    e->hash_next = NULL;
    e->last_access = ++c->tick;
    if (c->head) c->head->prev = e;
    c->head = e;
    if (!c->tail) c->tail = e;
    // insert into hash bucket
    uint64_t h = hash_fn(key) % c->nbuckets;
    e->hash_next = c->buckets[h];
    c->buckets[h] = e;
    c->total_bytes += size;
}

static void cache_get(cache_t *c, const char *key, void **out_data, size_t *out_size) {
    pthread_mutex_lock(&c->lock);
    cache_entry_t *e = cache_lookup_locked(c, key);
    if (e) {
        *out_data = e->data;
        *out_size = e->size;
    } else {
        *out_data = NULL;
        *out_size = 0;
    }
    pthread_mutex_unlock(&c->lock);
}

static void cache_put(cache_t *c, const char *key, void *data, size_t size) {
    pthread_mutex_lock(&c->lock);
    cache_put_locked(c, key, data, size);
    pthread_mutex_unlock(&c->lock);
}

/*** Simple thread pool + connection dispatch ***/
typedef struct conn_task {
    int fd;
    struct conn_task *next;
} conn_task_t;

typedef struct {
    conn_task_t *head, *tail;
    pthread_mutex_t lock;
    pthread_cond_t cond;
    bool stopping;
} task_queue_t;

static void task_queue_init(task_queue_t *q) {
    q->head = q->tail = NULL;
    pthread_mutex_init(&q->lock, NULL);
    pthread_cond_init(&q->cond, NULL);
    q->stopping = false;
}

static void task_queue_push(task_queue_t *q, int fd) {
    conn_task_t *t = malloc(sizeof(conn_task_t));
    t->fd = fd; t->next = NULL;
    pthread_mutex_lock(&q->lock);
    if (q->tail) q->tail->next = t;
    else q->head = t;
    q->tail = t;
    pthread_cond_signal(&q->cond);
    pthread_mutex_unlock(&q->lock);
}

static int task_queue_pop(task_queue_t *q) {
    pthread_mutex_lock(&q->lock);
    while (!q->head && !q->stopping) {
        pthread_cond_wait(&q->cond, &q->lock);
    }
    if (q->stopping && !q->head) {
        pthread_mutex_unlock(&q->lock);
        return -1;
    }
    conn_task_t *t = q->head;
    q->head = t->next;
    if (!q->head) q->tail = NULL;
    int fd = t->fd;
    free(t);
    pthread_mutex_unlock(&q->lock);
    return fd;
}

static void task_queue_stop(task_queue_t *q) {
    pthread_mutex_lock(&q->lock);
    q->stopping = true;
    pthread_cond_broadcast(&q->cond);
    pthread_mutex_unlock(&q->lock);
}

/*** Minimal HTTP handling ***/

typedef struct {
    int fd;
    char method[8];
    char path[1024];
    char version[32];
} http_req_t;

static int http_parse_request(const char *buf, http_req_t *req) {
    // Very minimal parsing: METHOD SP PATH SP VERSION CRLF
    // e.g. "GET /index.html HTTP/1.1\r\n"
    const char *p = buf;
    if (sscanf(p, "%7s %1023s %31s", req->method, req->path, req->version) < 2) return -1;
    return 0;
}

static const char *guess_mime(const char *path) {
    const char *ext = strrchr(path, '.');
    if (!ext) return "application/octet-stream";
    if (strcmp(ext, ".html") == 0 || strcmp(ext, ".htm") == 0) return "text/html";
    if (strcmp(ext, ".css") == 0) return "text/css";
    if (strcmp(ext, ".js") == 0) return "application/javascript";
    if (strcmp(ext, ".png") == 0) return "image/png";
    if (strcmp(ext, ".jpg") == 0 || strcmp(ext, ".jpeg") == 0) return "image/jpeg";
    if (strcmp(ext, ".gif") == 0) return "image/gif";
    if (strcmp(ext, ".svg") == 0) return "image/svg+xml";
    if (strcmp(ext, ".json") == 0) return "application/json";
    if (strcmp(ext, ".txt") == 0) return "text/plain";
    return "application/octet-stream";
}

/*** Server global state ***/
static cache_t *global_cache = NULL;
static char *www_root = NULL;
static task_queue_t global_queue;

/*** Worker logic: handle connection on fd ***/
static void handle_client(int fd) {
    arena_t arena;
    arena_init(&arena, 16 * 1024); // small per-request arena
    char buf[REQ_BUF_SIZE];
    ssize_t n = recv(fd, buf, sizeof(buf) - 1, 0);
    if (n <= 0) {
        close(fd);
        arena_free(&arena);
        return;
    }
    buf[n] = '\0';
    http_req_t req = { .fd = fd };
    if (http_parse_request(buf, &req) != 0) {
        // bad request
        const char *resp = "HTTP/1.0 400 Bad Request\r\nContent-Length:11\r\n\r\nBad Request";
        send(fd, resp, strlen(resp), 0);
        close(fd);
        arena_free(&arena);
        return;
    }
    // Only support GET
    if (strcmp(req.method, "GET") != 0) {
        const char *resp = "HTTP/1.0 405 Method Not Allowed\r\nContent-Length:18\r\n\r\nMethod Not Allowed";
        send(fd, resp, strlen(resp), 0);
        close(fd);
        arena_free(&arena);
        return;
    }
    // Prevent path traversal
    char clean_path[2048];
    if (strcmp(req.path, "/") == 0) strcpy(clean_path, "/index.html");
    else strncpy(clean_path, req.path, sizeof(clean_path)-1);
    clean_path[sizeof(clean_path)-1] = '\0';
    if (strstr(clean_path, "..")) {
        const char *resp = "HTTP/1.0 403 Forbidden\r\nContent-Length:9\r\n\r\nForbidden";
        send(fd, resp, strlen(resp), 0);
        close(fd);
        arena_free(&arena);
        return;
    }
    // build full filesystem path
    char fullpath[4096];
    snprintf(fullpath, sizeof(fullpath), "%s%s", www_root, clean_path);
    // check cache
    void *data = NULL;
    size_t sz = 0;
    cache_get(global_cache, fullpath, &data, &sz);
    if (data) {
        // send from cache
        const char *mime = guess_mime(fullpath);
        char hdr[256];
        int hdrlen = snprintf(hdr, sizeof(hdr),
            "HTTP/1.0 200 OK\r\nContent-Length: %zu\r\nContent-Type: %s\r\n\r\n", sz, mime);
        send(fd, hdr, hdrlen, 0);
        send(fd, data
