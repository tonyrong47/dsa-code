import java.util.*;

class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        Map<Integer, Integer> map = new HashMap<Integer, Integer>();
        for(int num: nums){
            map.put(num, map.getOrDefault(num, 0)+1);
        }

        List<Map.Entry<Integer, Integer>> entryList = new ArrayList<>(map.entrySet());

        entryList.sort((entry1, entry2) -> entry2.getValue().compareTo(entry1.getValue()));

        int res[] = new int[k];
        for(int i=0; i<k; i++){
            res[i] = entryList.get(i).getKey();
        }

        return res;
    }
}

public class Main {
    public static void main(String[] args) {
        Solution solution = new Solution();

        int[] nums1 = {1, 1, 1, 2, 2, 3};
        int k1 = 2;
        System.out.println("Output: " + Arrays.toString(solution.topKFrequent(nums1, k1))); // Expected: [1, 2]

        int[] nums2 = {1};
        int k2 = 1;
        System.out.println("Output: " + Arrays.toString(solution.topKFrequent(nums2, k2))); // Expected: [1]

        int[] nums3 = {1, 2, 1, 2, 1, 2, 3, 1, 3, 2};
        int k3 = 2;
        System.out.println("Output: " + Arrays.toString(solution.topKFrequent(nums3, k3))); // Expected: [1, 2]
    }
}
