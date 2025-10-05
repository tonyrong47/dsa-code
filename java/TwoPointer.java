/**
 * TwoPointer.java
 *
 * This class demonstrates the Two Pointer technique to find a pair
 * in a sorted array whose sum equals a given target value.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
public class TwoPointer {
    public static void pointer(int[] array, int target) {
        int left = 0;                  // Initialize left pointer at start
        int right = array.length - 1;  // Initialize right pointer at end

        while (left < right) {
            int sum = array[left] + array[right];

            if (sum == target) {
                System.out.println("Pair found: " + array[left] + " " + array[right]);
                return;  // Stop after finding the first pair
            } else if (sum < target) {
                left++;  // Move left pointer to increase sum
            } else {
                right--; // Move right pointer to decrease sum
            }
        }

        // If no pair is found
        System.out.println("No pair found");
    }

    // Sample main method to test the code
    public static void main(String[] args) {
        int[] array = {1, 2, 3, 4, 6};
        int target = 6;

        pointer(array, target); // Expected output: Pair found: 2 4
    }
}
