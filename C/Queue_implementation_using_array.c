#include <stdio.h>
#define MAX 5

int queue[MAX], front = -1, rear = -1;

// Insert element into queue
void enqueue(int val) {
    if (rear == MAX - 1)
        printf("Queue Overflow\n");
    else {
        if (front == -1) front = 0; // First element
        queue[++rear] = val;
    }
}

// Remove element from queue
int dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow\n");
        return -1;
    }
    return queue[front++];
}

// Display queue contents
void display() {
    if (front == -1 || front > rear) printf("Queue is empty\n");
    else {
        printf("Queue elements: ");
        for (int i = front; i <= rear; i++)
            printf("%d ", queue[i]);
        printf("\n");
    }
}

int main() {
    enqueue(5);
    enqueue(10);
    enqueue(15);
    display();
    printf("Dequeued: %d\n", dequeue());
    display();
    return 0;
}
