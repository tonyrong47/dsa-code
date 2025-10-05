#include <stdio.h>
#define MAX 5

int stack[MAX], top = -1;

// Push element onto stack
void push(int val) {
    if (top == MAX - 1)
        printf("Stack Overflow\n");
    else
        stack[++top] = val;
}

// Pop element from stack
int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[top--];
}

// Display stack contents
void display() {
    if (top == -1) printf("Stack is empty\n");
    else {
        printf("Stack elements: ");
        for (int i = top; i >= 0; i--)
            printf("%d ", stack[i]);
        printf("\n");
    }
}

int main() {
    push(10);
    push(20);
    push(30);
    display();
    printf("Popped: %d\n", pop());
    display();
    return 0;
}
