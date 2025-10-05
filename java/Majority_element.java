public class Majority_element {
    public static void main(String[] args) {
        int[] nums = {2, 7, 11, 15};
        int target = 9;
        Solution sol = new Solution();
        sol.twoSum(nums, target);
    }
}

class Solution {
    public int[] twoSum(int[] nums, int target) {

        int add = 0, n = nums.length;
        int i = 0;

        while (i < n - 1) { // Prevent out-of-bounds
            add = nums[i] + nums[i + 1];
            if (add == target) {
                System.out.print(nums[i]);
                System.out.println(nums[i + 1]);
            }
            i++;
        }
        return null; 
    }
}