#Find Middle of Linked List

class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

def find_middle(head):
    slow = fast = head
    while fast and fast.next:
        slow = slow.next
        fast = fast.next.next
    return slow.data

# Example usage
head = Node(1)
head.next = Node(2)
head.next.next = Node(3)
head.next.next.next = Node(4)

print("Middle element:", find_middle(head))  # Output: 3
