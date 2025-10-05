#include <atomic>
#include <iostream>
#include <thread>
#include <vector>

template <typename T>
class LockFreeQueue {
public:
    explicit LockFreeQueue(size_t size)
        : size_(size), buffer_(new T[size]), head_(0), tail_(0) {}

    ~LockFreeQueue() {
        delete[] buffer_;
    }

    bool enqueue(const T& value) {
        size_t current_tail = tail_.load(std::memory_order_relaxed);
        size_t next_tail = (current_tail + 1) % size_;
        if (next_tail == head_.load(std::memory_order_acquire)) {
            return false; // Queue is full
        }
        buffer_[current_tail] = value;
        tail_.store(next_tail, std::memory_order_release);
        return true;
    }

    bool dequeue(T& value) {
        size_t current_head = head_.load(std::memory_order_relaxed);
        if (current_head == tail_.load(std::memory_order_acquire)) {
            return false; // Queue is empty
        }
        value = buffer_[current_head];
        head_.store((current_head + 1) % size_, std::memory_order_release);
        return true;
    }

private:
    const size_t size_;
    T* const buffer_;
    std::atomic<size_t> head_;
    std::atomic<size_t> tail_;
};

void producer(LockFreeQueue<int>& queue) {
    for (int i = 0; i < 100; ++i) {
        while (!queue.enqueue(i)) {
            std::this_thread::yield(); // Retry if queue is full
        }
    }
}

void consumer(LockFreeQueue<int>& queue) {
    int value;
    for (int i = 0; i < 100; ++i) {
        while (!queue.dequeue(value)) {
            std::this_thread::yield(); // Retry if queue is empty
        }
        std::cout << "Consumed: " << value << std::endl;
    }
}

int main() {
    LockFreeQueue<int> queue(100);
    std::thread prod(producer, std::ref(queue));
    std::thread cons(consumer, std::ref(queue));

    prod.join();
    cons.join();

    return 0;
}
