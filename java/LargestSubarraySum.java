public class LargestSubarraySum {
    public static void main(String[] args) {
        int[] arr = new int[] { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
        int ans = findLargestSubArraySum(arr);

        System.out.println("Largest subarray sum is " + ans);
    }

    public static int findLargestSubArraySum(int[] arr) {
        int ans = 0;
        int currSum = 0;
        int n = arr.length;

        // Kadane algorithm 
        for (int i = 0; i < n; i++) {
            currSum += arr[i];
            ans = Math.max(ans, currSum);
            currSum = Math.max(0, currSum);
        }
        return ans;
    }
}
