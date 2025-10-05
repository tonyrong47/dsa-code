// LinkedListCycleDetection.java
// This class implements Floyd's Cycle Detection Algorithm to detect if a linked list has a cycle.
// Time Complexity: O(n), Space Complexity: O(1)

class ListNode {
    int val;
    ListNode next;
    ListNode(int x) {
        val = x;
        next = null;
    }
}

public class LinkedListCycleDetection {

    // Method to detect cycle in linked list using two pointers
    public boolean hasCycle(ListNode head) {
        if (head == null || head.next == null) {
            return false; // No cycle if list is empty or has only one node
        }

        ListNode slow = head; // Moves one step at a time
        ListNode fast = head; // Moves two steps at a time

        while (fast != null && fast.next != null) {
            slow = slow.next;          // Move slow pointer by 1
            fast = fast.next.next;     // Move fast pointer by 2

            if (slow == fast) {
                return true; // Cycle detected
            }
        }

        return false; // No cycle found
    }

    // Main method for testing
    public static void main(String[] args) {
        LinkedListCycleDetection detector = new LinkedListCycleDetection();

        // Create a linked list: 1 -> 2 -> 3 -> 4 -> 2 (cycle back to 2)
        ListNode node1 = new ListNode(1);
        ListNode node2 = new ListNode(2);
        ListNode node3 = new ListNode(3);
        ListNode node4 = new ListNode(4);

        node1.next = node2;
        node2.next = node3;
        node3.next = node4;
        node4.next = node2; // Creates cycle

        boolean result = detector.hasCycle(node1);
        System.out.println("Cycle detected: " + result); // Should print true

        // Test with no cycle: 1 -> 2 -> 3 -> null
        ListNode nodeA = new ListNode(1);
        ListNode nodeB = new ListNode(2);
        ListNode nodeC = new ListNode(3);

        nodeA.next = nodeB;
        nodeB.next = nodeC;

        boolean result2 = detector.hasCycle(nodeA);
        System.out.println("Cycle detected: " + result2); // Should print false
    }
}