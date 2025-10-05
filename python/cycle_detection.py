class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None

    def append(self, data):
        new_node = Node(data)
        if not self.head:
            self.head = new_node
            return
        temp = self.head
        while temp.next:
            temp = temp.next
        temp.next = new_node

    def create_cycle(self, pos):
        """Creates a cycle in the linked list at the given position"""
        if pos < 0:
            return
        cycle_node = self.head
        last_node = self.head
        count = 0
        while count < pos and cycle_node:
            cycle_node = cycle_node.next
            count += 1
        while last_node.next:
            last_node = last_node.next
        last_node.next = cycle_node

    def detect_cycle(self):
        """Floyd’s Cycle Detection Algorithm (Tortoise and Hare)"""
        slow = self.head
        fast = self.head
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
            if slow == fast:
                return True
        return False


# Example usage:
if __name__ == "__main__":
    ll = LinkedList()
    ll.append(1)
    ll.append(2)
    ll.append(3)
    ll.append(4)
    ll.append(5)

    print("Cycle detected?" , ll.detect_cycle())  # False

    ll.create_cycle(2)  # Create cycle at node with value 3
    print("Cycle detected?" , ll.detect_cycle())  # True
