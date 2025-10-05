class ListNode:
    """Node class for linked list"""
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def reverse_linked_list(head):
    """
    Reverse a singly linked list
    Time Complexity: O(n)
    Space Complexity: O(1)
    """
    prev = None
    current = head
    
    while current:
        next_temp = current.next  # Store next node
        current.next = prev       # Reverse the link
        prev = current           # Move prev forward
        current = next_temp      # Move current forward
    
    return prev  # prev is the new head

def print_list(head):
    """Helper function to print the linked list"""
    result = []
    current = head
    while current:
        result.append(current.val)
        current = current.next
    return result

# Test the function
if __name__ == "__main__":
    # Create a linked list: 1 -> 2 -> 3 -> 4 -> 5
    head = ListNode(1)
    head.next = ListNode(2)
    head.next.next = ListNode(3)
    head.next.next.next = ListNode(4)
    head.next.next.next.next = ListNode(5)
    
    print(f"Original list: {print_list(head)}")
    
    # Reverse the linked list
    reversed_head = reverse_linked_list(head)
    print(f"Reversed list: {print_list(reversed_head)}")