# Reverse a Linked List

class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

def reverse_linked_list(head):
    prev = None
    current = head
    while current:
        nxt = current.next
        current.next = prev
        prev = current
        current = nxt 
    return prev

# Example usage
head = Node(1)
head.next = Node(2)
head.next.next = Node(3)

new_head = reverse_linked_list(head)
while new_head:
    print(new_head.data, end=" -> ")
    new_head = new_head.next
# Output: 3 -> 2 -> 1 ->
