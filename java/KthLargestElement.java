//its the solution for leetcode 215 
//sorting the array using quick select in Time Complexity o(n)(avg) && Space Complexity o(1)

class Solution {
    public int findKthLargest(int[] nums, int k) {
       int n = nums.length;
        int target = n - k;
        int left = 0, right = n - 1;

        Random rand = new Random();

        while (left <= right) {
            int pivotIndex = left + rand.nextInt(right - left + 1);
            int pivot = nums[pivotIndex];

            int lt = left, i = left, gt = right;
            while (i <= gt) {
                if (nums[i] < pivot) {
                    swap(nums, lt, i);
                    lt++;
                    i++;
                } else if (nums[i] > pivot) {
                    swap(nums, i, gt);
                    gt--;
                } else {
                    i++;
                }
            }
            if (target >= lt && target <= gt) {
                return pivot; 
            } else if (target < lt) {
                right = lt - 1; 
            } else {
                left = gt + 1;  
            }
        }
        return -1; 
    }

    private void swap(int[] nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
}
