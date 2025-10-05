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
        new_node.next = self.head  # Point to old head
        self.head = new_node       # Update head

    # Display the list
    def display(self):
        temp = self.head
        while temp:
            print(temp.data, end=" -> ")
            temp = temp.next
        print("NULL")

# sample usage
ll = LinkedList()
ll.insert_at_start(10)
ll.insert_at_start(20)
ll.insert_at_start(30)

print("Linked List:")
ll.display()
