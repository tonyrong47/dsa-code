class Solution {
    public int rob(int[] nums) {

        if(nums.length==1) return nums[0];
        if(nums.length==2) return Math.max(nums[0], nums[1]);

        int prev2 = 0;
        int prev1 = nums[0];

        for(int i=1; i<nums.length-1; i++){
            int curr = Math.max(nums[i]+prev2, prev1);
            prev2 = prev1;
            prev1= curr;
        }

        int max1 = prev1;

        prev2 = 0;
        prev1 = nums[1];

        for(int i=2; i<nums.length; i++){
            int curr = Math.max(nums[i] + prev2, prev1);
            prev2 = prev1;
            prev1= curr;
        }

        return Math.max(max1, prev1);
    }
}

public class Main {
    public static void main(String[] args) {
        Solution sol = new Solution();

        int[] nums1 = {2, 3, 2};
        System.out.println("Maximum amount robbed (Example 1): " + sol.rob(nums1));

        int[] nums2 = {1, 2, 3, 1};
        System.out.println("Maximum amount robbed (Example 2): " + sol.rob(nums2));

        int[] nums3 = {1, 2, 3};
        System.out.println("Maximum amount robbed (Example 3): " + sol.rob(nums3));

        int[] nums4 = {200, 3, 140, 20, 10};
        System.out.println("Maximum amount robbed (Extra Test): " + sol.rob(nums4));
    }
}