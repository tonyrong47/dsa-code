
import java.util.*;

public class Threesum {
    
    /**
     * Finds all unique triplets in the array that sum to zero
     * Time Complexity: O(n^2)
     * Space Complexity: O(1) excluding the output array
     * 
     * @param nums input array of integers
     * @return list of triplets that sum to zero
     */
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> result = new ArrayList<>();
        
        // Handle edge cases
        if (nums == null || nums.length < 3) {
            return result;
        }
        
        // Sort the array to enable two-pointer technique
        Arrays.sort(nums);
        
        for (int i = 0; i < nums.length - 2; i++) {
            // Skip duplicate values for the first element
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            
            int left = i + 1;
            int right = nums.length - 1;
            
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                
                if (sum == 0) {
                    // Found a valid triplet
                    result.add(Arrays.asList(nums[i], nums[left], nums[right]));
                    
                    // Skip duplicates for left pointer
                    while (left < right && nums[left] == nums[left + 1]) {
                        left++;
                    }
                    
                    // Skip duplicates for right pointer
                    while (left < right && nums[right] == nums[right - 1]) {
                        right--;
                    }
                    
                    left++;
                    right--;
                } else if (sum < 0) {
                    // Sum is too small, move left pointer right
                    left++;
                } else {
                    // Sum is too large, move right pointer left
                    right--;
                }
            }
        }
        
        return result;
    }
    
    
    public List<List<Integer>> threeSumTarget(int[] nums, int target) {
        List<List<Integer>> result = new ArrayList<>();
        
        if (nums == null || nums.length < 3) {
            return result;
        }
        
        Arrays.sort(nums);
        
        for (int i = 0; i < nums.length - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            
            int left = i + 1;
            int right = nums.length - 1;
            
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                
                if (sum == target) {
                    result.add(Arrays.asList(nums[i], nums[left], nums[right]));
                    
                    while (left < right && nums[left] == nums[left + 1]) {
                        left++;
                    }
                    while (left < right && nums[right] == nums[right - 1]) {
                        right--;
                    }
                    
                    left++;
                    right--;
                } else if (sum < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }
        
        return result;
    }
    
    /**
     * Helper method to print the results
     */
    public void printTriplets(List<List<Integer>> triplets) {
        if (triplets.isEmpty()) {
            System.out.println("No triplets found.");
            return;
        }
        
        System.out.println("Found triplets:");
        for (List<Integer> triplet : triplets) {
            System.out.println(triplet);
        }
    }
    
    /**
     * Main method for testing
     */
    public static void main(String[] args) {
        Threesum solution = new Threesum();
        
        // Test case 1: Basic example
        int[] nums1 = {-1, 0, 1, 2, -1, -4};
        System.out.println("Test case 1: " + Arrays.toString(nums1));
        List<List<Integer>> result1 = solution.threeSum(nums1);
        solution.printTriplets(result1);
        System.out.println();
        
        // Test case 2: No triplets sum to zero
        int[] nums2 = {0, 1, 1};
        System.out.println("Test case 2: " + Arrays.toString(nums2));
        List<List<Integer>> result2 = solution.threeSum(nums2);
        solution.printTriplets(result2);
        System.out.println();
        
        // Test case 3: All zeros
        int[] nums3 = {0, 0, 0};
        System.out.println("Test case 3: " + Arrays.toString(nums3));
        List<List<Integer>> result3 = solution.threeSum(nums3);
        solution.printTriplets(result3);
        System.out.println();
        
        // Test case 4: Custom target
        int[] nums4 = {-1, 0, 1, 2, -1, -4};
        int target = 0;
        System.out.println("Test case 4 (target=" + target + "): " + Arrays.toString(nums4));
        List<List<Integer>> result4 = solution.threeSumTarget(nums4, target);
        solution.printTriplets(result4);
    }
}
