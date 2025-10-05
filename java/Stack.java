public class Stack {
    private int[] stack;
    private int top;
    private int capacity;
    
    public Stack(int size) {
        capacity = size;
        stack = new int[capacity];
        top = -1;
    }
    
    public boolean isEmpty() {
        return top == -1;
    }
    
    public boolean isFull() {
        return top == capacity - 1;
    }
    
    public void push(int item) {
        if (isFull()) {
            System.out.println("Stack is full");
            return;
        }
        stack[++top] = item;
    }
    
    public int pop() {
        if (isEmpty()) {
            System.out.println("Stack is empty");
            return -1;
        }
        return stack[top--];
    }
    
    public int peek() {
        if (isEmpty()) {
            return -1;
        }
        return stack[top];
    }
    
    public void display() {
        for (int i = top; i >= 0; i--) {
            System.out.print(stack[i] + " ");
        }
        System.out.println();
    }
    
    public static void main(String[] args) {
        Stack stack = new Stack(5);
        stack.push(10);
        stack.push(20);
        stack.push(30);
        System.out.print("Stack: ");
        stack.display();
        System.out.println("Popped: " + stack.pop());
        System.out.println("Top element: " + stack.peek());
    }
}
