# Node class
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

# Linked List class
class LinkedList:
    def __init__(self):
        self.head = None

    # Add a new node at the end
    def add(self, data):
        new_node = Node(data)
        if not self.head:
            self.head = new_node
            return
        current = self.head
        while current.next:
            current = current.next
        current.next = new_node

    # Subtract a value from each node
    def subtract(self, value):
        current = self.head
        while current:
            current.data -= value
            current = current.next

    # Print the linked list
    def print_list(self):
        current = self.head
        while current:
            print(current.data, end=" -> ")
            current = current.next
        print("None")


# Example usage
ll = LinkedList()
ll.add(10)
ll.add(20)
ll.add(30)

print("Original Linked List:")
ll.print_list()

ll.subtract(5)
print("After subtracting 5 from each node:")
ll.print_list()
