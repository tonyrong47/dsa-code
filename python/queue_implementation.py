class Queue:
    """
    Queue implementation using list
    FIFO (First In First Out) data structure
    """
    
    def __init__(self):
        self.items = []
    
    def enqueue(self, item):
        """Add an item to the rear of the queue"""
        self.items.append(item)
    
    def dequeue(self):
        """Remove and return the front item from the queue"""
        if self.is_empty():
            raise IndexError("dequeue from empty queue")
        return self.items.pop(0)
    
    def front(self):
        """Return the front item without removing it"""
        if self.is_empty():
            raise IndexError("front from empty queue")
        return self.items[0]
    
    def is_empty(self):
        """Check if the queue is empty"""
        return len(self.items) == 0
    
    def size(self):
        """Return the number of items in the queue"""
        return len(self.items)
    
    def __str__(self):
        return str(self.items)

# Test the Queue
if __name__ == "__main__":
    queue = Queue()
    
    # Enqueue elements
    queue.enqueue('A')
    queue.enqueue('B')
    queue.enqueue('C')
    print(f"Queue after enqueuing A, B, C: {queue}")
    
    # Check front element
    print(f"Front element: {queue.front()}")
    
    # Dequeue elements
    print(f"Dequeued: {queue.dequeue()}")
    print(f"Queue after dequeuing: {queue}")
    
    print(f"Queue size: {queue.size()}")
    print(f"Is empty: {queue.is_empty()}")