//You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

// Merge all the linked-lists into one sorted linked-list and return it.

import java.util.*;

public class Merge_K_Sortedlists {
    
    /**
     * Definition for singly-linked list node
     */
    static class ListNode {
        int val;
        ListNode next;
        
        ListNode() {}
        
        ListNode(int val) {
            this.val = val;
        }
        
        ListNode(int val, ListNode next) {
            this.val = val;
            this.next = next;
        }
        
        @Override
        public String toString() {
            StringBuilder sb = new StringBuilder();
            ListNode current = this;
            while (current != null) {
                sb.append(current.val);
                if (current.next != null) {
                    sb.append(" -> ");
                }
                current = current.next;
            }
            return sb.toString();
        }
    }
    
    /**
     * Approach 1: Using Min-Heap (Priority Queue) - Most Efficient
     * Time Complexity: O(N log k) where N is total number of nodes and k is number of lists
     * Space Complexity: O(k) for the priority queue
     * 
     * @param lists array of sorted linked lists
     * @return merged sorted linked list
     */
    public ListNode mergeKLists(ListNode[] lists) {
        if (lists == null || lists.length == 0) {
            return null;
        }
        
        // Create a min-heap based on node values
        PriorityQueue<ListNode> minHeap = new PriorityQueue<>((a, b) -> a.val - b.val);
        
        // Add the head of each non-null list to the heap
        for (ListNode list : lists) {
            if (list != null) {
                minHeap.offer(list);
            }
        }
        
        ListNode dummy = new ListNode(0);
        ListNode current = dummy;
        
        // Process nodes from the heap
        while (!minHeap.isEmpty()) {
            ListNode smallest = minHeap.poll();
            current.next = smallest;
            current = current.next;
            
            // If the smallest node has a next node, add it to the heap
            if (smallest.next != null) {
                minHeap.offer(smallest.next);
            }
        }
        
        return dummy.next;
    }
    
    /**
     * Approach 2: Divide and Conquer
     * Time Complexity: O(N log k)
     * Space Complexity: O(log k) for recursion stack
     * 
     * @param lists array of sorted linked lists
     * @return merged sorted linked list
     */
    public ListNode mergeKListsDivideConquer(ListNode[] lists) {
        if (lists == null || lists.length == 0) {
            return null;
        }
        
        return mergeKListsHelper(lists, 0, lists.length - 1);
    }
    
    private ListNode mergeKListsHelper(ListNode[] lists, int start, int end) {
        if (start == end) {
            return lists[start];
        }
        
        if (start < end) {
            int mid = start + (end - start) / 2;
            ListNode left = mergeKListsHelper(lists, start, mid);
            ListNode right = mergeKListsHelper(lists, mid + 1, end);
            return mergeTwoLists(left, right);
        }
        
        return null;
    }
    
    /**
     * Helper method to merge two sorted linked lists
     * Time Complexity: O(m + n)
     * Space Complexity: O(1)
     */
    private ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        ListNode dummy = new ListNode(0);
        ListNode current = dummy;
        
        while (l1 != null && l2 != null) {
            if (l1.val <= l2.val) {
                current.next = l1;
                l1 = l1.next;
            } else {
                current.next = l2;
                l2 = l2.next;
            }
            current = current.next;
        }
        
        // Attach remaining nodes
        if (l1 != null) {
            current.next = l1;
        }
        if (l2 != null) {
            current.next = l2;
        }
        
        return dummy.next;
    }
    
    /**
     * Approach 3: Brute Force - Merge lists one by one
     * Time Complexity: O(k * N) where k is number of lists and N is total nodes
     * Space Complexity: O(1)
     * 
     * @param lists array of sorted linked lists
     * @return merged sorted linked list
     */
    public ListNode mergeKListsBruteForce(ListNode[] lists) {
        if (lists == null || lists.length == 0) {
            return null;
        }
        
        ListNode result = lists[0];
        
        for (int i = 1; i < lists.length; i++) {
            result = mergeTwoLists(result, lists[i]);
        }
        
        return result;
    }
    
    /**
     * Helper method to create a linked list from an array
     */
    public ListNode createList(int[] values) {
        if (values == null || values.length == 0) {
            return null;
        }
        
        ListNode head = new ListNode(values[0]);
        ListNode current = head;
        
        for (int i = 1; i < values.length; i++) {
            current.next = new ListNode(values[i]);
            current = current.next;
        }
        
        return head;
    }
    
    /**
     * Helper method to convert linked list to array for easy testing
     */
    public List<Integer> listToArray(ListNode head) {
        List<Integer> result = new ArrayList<>();
        ListNode current = head;
        
        while (current != null) {
            result.add(current.val);
            current = current.next;
        }
        
        return result;
    }
    
    /**
     * Main method for testing
     */
    public static void main(String[] args) {
        Merge_K_Sortedlists solution = new Merge_K_Sortedlists();
        
        // Test case 1: Basic example
        System.out.println("=== Test Case 1: Basic Example ===");
        ListNode list1 = solution.createList(new int[]{1, 4, 5});
        ListNode list2 = solution.createList(new int[]{1, 3, 4});
        ListNode list3 = solution.createList(new int[]{2, 6});
        
        ListNode[] lists1 = {list1, list2, list3};
        
        System.out.println("Input lists:");
        System.out.println("List 1: " + list1);
        System.out.println("List 2: " + list2);
        System.out.println("List 3: " + list3);
        
        ListNode result1 = solution.mergeKLists(lists1);
        System.out.println("Merged result (Min-Heap): " + result1);
        System.out.println("As array: " + solution.listToArray(result1));
        System.out.println();
        
        // Test case 2: Empty lists
        System.out.println("=== Test Case 2: Empty Lists ===");
        ListNode[] lists2 = {};
        ListNode result2 = solution.mergeKLists(lists2);
        System.out.println("Merged result: " + result2);
        System.out.println();
        
        // Test case 3: Single list
        System.out.println("=== Test Case 3: Single List ===");
        ListNode singleList = solution.createList(new int[]{1, 2, 3});
        ListNode[] lists3 = {singleList};
        ListNode result3 = solution.mergeKLists(lists3);
        System.out.println("Input: " + singleList);
        System.out.println("Merged result: " + result3);
        System.out.println();
        
        // Test case 4: Lists with null values
        System.out.println("=== Test Case 4: Lists with Nulls ===");
        ListNode list4a = solution.createList(new int[]{1, 2});
        ListNode list4b = null;
        ListNode list4c = solution.createList(new int[]{3, 4});
        
        ListNode[] lists4 = {list4a, list4b, list4c};
        ListNode result4 = solution.mergeKLists(lists4);
        System.out.println("Merged result: " + result4);
        System.out.println();
        
        // Test case 5: Compare different approaches
        System.out.println("=== Test Case 5: Comparing Approaches ===");
        ListNode list5a = solution.createList(new int[]{1, 4, 5});
        ListNode list5b = solution.createList(new int[]{1, 3, 4});
        ListNode list5c = solution.createList(new int[]{2, 6});
        
        ListNode[] lists5_heap = {list5a, list5b, list5c};
        
        // Recreate lists for other approaches (since nodes get modified)
        ListNode[] lists5_dc = {
            solution.createList(new int[]{1, 4, 5}),
            solution.createList(new int[]{1, 3, 4}),
            solution.createList(new int[]{2, 6})
        };
        
        ListNode[] lists5_bf = {
            solution.createList(new int[]{1, 4, 5}),
            solution.createList(new int[]{1, 3, 4}),
            solution.createList(new int[]{2, 6})
        };
        
        long startTime, endTime;
        
        // Min-Heap approach
        startTime = System.nanoTime();
        ListNode resultHeap = solution.mergeKLists(lists5_heap);
        endTime = System.nanoTime();
        System.out.println("Min-Heap result: " + solution.listToArray(resultHeap));
        System.out.println("Min-Heap time: " + (endTime - startTime) + " ns");
        
        // Divide and Conquer approach
        startTime = System.nanoTime();
        ListNode resultDC = solution.mergeKListsDivideConquer(lists5_dc);
        endTime = System.nanoTime();
        System.out.println("Divide & Conquer result: " + solution.listToArray(resultDC));
        System.out.println("Divide & Conquer time: " + (endTime - startTime) + " ns");
        
        // Brute Force approach
        startTime = System.nanoTime();
        ListNode resultBF = solution.mergeKListsBruteForce(lists5_bf);
        endTime = System.nanoTime();
        System.out.println("Brute Force result: " + solution.listToArray(resultBF));
        System.out.println("Brute Force time: " + (endTime - startTime) + " ns");
    }
}
