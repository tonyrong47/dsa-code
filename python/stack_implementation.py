class Stack:
    """
    Stack implementation using list
    LIFO (Last In First Out) data structure
    """
    
    def __init__(self):
        self.items = []
    
    def push(self, item):
        """Add an item to the top of the stack"""
        self.items.append(item)
    
    def pop(self):
        """Remove and return the top item from the stack"""
        if self.is_empty():
            raise IndexError("pop from empty stack")
        return self.items.pop()
    
    def peek(self):
        """Return the top item without removing it"""
        if self.is_empty():
            raise IndexError("peek from empty stack")
        return self.items[-1]
    
    def is_empty(self):
        """Check if the stack is empty"""
        return len(self.items) == 0
    
    def size(self):
        """Return the number of items in the stack"""
        return len(self.items)
    
    def __str__(self):
        return str(self.items)

# Test the Stack
if __name__ == "__main__":
    stack = Stack()
    
    # Push elements
    stack.push(1)
    stack.push(2)
    stack.push(3)
    print(f"Stack after pushing 1, 2, 3: {stack}")
    
    # Peek at top element
    print(f"Top element: {stack.peek()}")
    
    # Pop elements
    print(f"Popped: {stack.pop()}")
    print(f"Stack after popping: {stack}")
    
    print(f"Stack size: {stack.size()}")
    print(f"Is empty: {stack.is_empty()}")