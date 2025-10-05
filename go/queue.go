package main

import "fmt"

type Queue struct {
	items []int
	front int
	rear  int
}

func NewQueue() *Queue {
	return &Queue{
		items: make([]int, 0),
		front: -1,
		rear:  -1,
	}
}

func (q *Queue) IsEmpty() bool {
	return q.front == -1
}

func (q *Queue) Enqueue(item int) {
	if q.IsEmpty() {
		q.front = 0
	}
	q.rear++
	q.items = append(q.items, item)
}

func (q *Queue) Dequeue() int {
	if q.IsEmpty() {
		return -1
	}
	
	item := q.items[q.front]
	q.front++
	
	if q.front > q.rear {
		q.front = -1
		q.rear = -1
	}
	
	return item
}

func (q *Queue) Display() {
	if q.IsEmpty() {
		fmt.Println("Queue is empty")
		return
	}
	
	for i := q.front; i <= q.rear; i++ {
		fmt.Print(q.items[i], " ")
	}
	fmt.Println()
}

func main() {
	queue := NewQueue()
	queue.Enqueue(10)
	queue.Enqueue(20)
	queue.Enqueue(30)
	fmt.Print("Queue: ")
	queue.Display()
	fmt.Println("Dequeued:", queue.Dequeue())
	fmt.Print("Queue after dequeue: ")
	queue.Display()
}
