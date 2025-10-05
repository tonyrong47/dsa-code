class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int m = nums1.length;
        int n = nums2.length;
        int[] arr3 = new int[m + n];
        int i = 0, j = 0, k = 0;

        while (i < m && j < n) {
            if (nums1[i] < nums2[j]) {
                arr3[k++] = nums1[i++];
            } else {
                arr3[k++] = nums2[j++];
            }
        }
        while (i < m) {
            arr3[k++] = nums1[i++];
        }
        while (j < n) {
            arr3[k++] = nums2[j++];
        }
        int mid = (m + n) / 2;
        if ((m + n) % 2 == 0) {
            return (arr3[mid - 1] + arr3[mid]) / 2.0;
        } else {
            return arr3[mid];
        }
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        int[] nums1 = {1, 3};
        int[] nums2 = {2};
        System.out.println(solution.findMedianSortedArrays(nums1, nums2));

        int[] nums1_2 = {1, 2};
        int[] nums2_2 = {3, 4};
      System.out.println(solution.findMedianSortedArrays(nums1_2, nums2_2));
    }
}