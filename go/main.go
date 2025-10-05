package main

import (
	"context"
	"fmt"
	"net/http"
	"sync"
	"time"
)

// RateLimiter controls request rate
type RateLimiter struct {
	tokens chan struct{}
	rate   time.Duration
}

func NewRateLimiter(rps int, interval time.Duration) *RateLimiter {
	rl := &RateLimiter{
		tokens: make(chan struct{}, rps),
		rate:   interval,
	}
	go func() {
		ticker := time.NewTicker(interval / time.Duration(rps))
		for range ticker.C {
			select {
			case rl.tokens <- struct{}{}:
			default:
			}
		}
	}()
	return rl
}

func (rl *RateLimiter) Wait(ctx context.Context) {
	select {
	case <-rl.tokens:
	case <-ctx.Done():
	}
}

// Coordinator simulates distributed coordination
type Coordinator struct {
	mu      sync.Mutex
	visited map[string]bool
}

func NewCoordinator() *Coordinator {
	return &Coordinator{visited: make(map[string]bool)}
}

func (c *Coordinator) Lock(url string) bool {
	c.mu.Lock()
	defer c.mu.Unlock()
	if c.visited[url] {
		return false
	}
	c.visited[url] = true
	return true
}

func (c *Coordinator) Unlock(url string) {
	// In real distributed system, unlock is handled externally
}

type Crawler struct {
	rateLimiter *RateLimiter
	coordinator *Coordinator
}

func NewCrawler(rl *RateLimiter, coord *Coordinator) *Crawler {
	return &Crawler{rateLimiter: rl, coordinator: coord}
}

func (c *Crawler) Crawl(ctx context.Context, urls []string) chan string {
	results := make(chan string)
	var wg sync.WaitGroup

	for _, url := range urls {
		wg.Add(1)
		go func(u string) {
			defer wg.Done()
			if c.coordinator.Lock(u) {
				defer c.coordinator.Unlock(u)

				c.rateLimiter.Wait(ctx)

				req, _ := http.NewRequestWithContext(ctx, "GET", u, nil)
				resp, err := http.DefaultClient.Do(req)
				if err != nil {
					results <- fmt.Sprintf("Failed to crawl %s: %v", u, err)
					return
				}
				defer resp.Body.Close()

				results <- fmt.Sprintf("Crawled %s - Status: %d", u, resp.StatusCode)
			} else {
				results <- fmt.Sprintf("Skipped %s - already crawled", u)
			}
		}(url)
	}

	go func() {
		wg.Wait()
		close(results)
	}()

	return results
}

func main() {
	ctx, cancel := context.WithTimeout(context.Background(), 20*time.Second)
	defer cancel()

	rateLimiter := NewRateLimiter(5, time.Second) // 5 requests/sec
	coordinator := NewCoordinator()
	crawler := NewCrawler(rateLimiter, coordinator)

	urls := []string{
		"https://golang.org",
		"https://github.com",
		"https://example.com",
		"https://google.com",
		"https://stackoverflow.com",
	}

	results := crawler.Crawl(ctx, urls)

	fmt.Println("Crawl results:")
	for res := range results {
		fmt.Println(res)
	}
}
