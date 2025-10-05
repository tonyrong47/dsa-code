class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None

    # Insert at start
    def insert_at_start(self, data):
        new_node = Node(data)
        new_node.next = self.head
        self.head = new_node

    # Insert at kth index (0-based index)
    def insert_at_index(self, data, k):
        new_node = Node(data)

        # If inserting at head
        if k == 0:
            new_node.next = self.head
            self.head = new_node
            return

        temp = self.head
        count = 0
        while temp is not None and count < k-1:
            temp = temp.next
            count += 1

        if temp is None:
            print("Index out of range")
            return

        new_node.next = temp.next
        temp.next = new_node

    # Delete at end
    def delete_at_end(self):
        if self.head is None:
            print("List is empty")
            return

        if self.head.next is None:
            self.head = None
            return

        temp = self.head
        while temp.next.next:
            temp = temp.next
        temp.next = None

    # Display the list
    def display(self):
        temp = self.head
        while temp:
            print(temp.data, end=" -> ")
            temp = temp.next
        print("NULL")


# Example usage
ll = LinkedList()
ll.insert_at_start(10)
ll.insert_at_start(20)
ll.insert_at_start(30)

print("Original Linked List:")
ll.display()

ll.insert_at_index(25, 1)   # Insert 25 at index 1
print("After inserting 25 at index 1:")
ll.display()

ll.insert_at_index(5, 0)    # Insert 5 at index 0 (start)
print("After inserting 5 at index 0:")
ll.display()

ll.insert_at_index(50, 10)  # Out of range
