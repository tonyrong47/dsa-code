/**
 * A utility class to find the maximum sum of a contiguous subarray
 * using Kadane's Algorithm.
 */
public class MaximumSubarray {

    /**
     * Finds the maximum sum of a contiguous subarray.
     *
     * @param nums the input array of integers
     * @return the maximum sum of a contiguous subarray
     */
    public static int maxSubArray(int[] nums) {

        int maxSum = nums[0];
        int currentMax = nums[0];

        for (int i = 1; i < nums.length; i++) {
            currentMax = Math.max(currentMax + nums[i], nums[i]); // Update the current maximum by including the current element
            maxSum = Math.max(maxSum, currentMax); // Update the result if the current maximum is greater
        }

        return maxSum;
    }

    public static void main(String[] args) {
        // Test cases
        int[] nums1 = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
        int[] nums2 = {1};
        int[] nums3 = {5, 4, -1, 7, 8};

        // Print the results
        System.out.println("Maximum Subarray Sum (Test Case 1): " + maxSubArray(nums1)); // Output: 6 (4, -1, 2, 1)
        System.out.println("Maximum Subarray Sum (Test Case 2): " + maxSubArray(nums2)); // Output: 1 (1)
        System.out.println("Maximum Subarray Sum (Test Case 3): " + maxSubArray(nums3)); // Output: 23 (5, 4, -1, 7, 8)
    }
}
