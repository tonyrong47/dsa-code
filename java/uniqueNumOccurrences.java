public class Solution {
    public static boolean uniqueOccurrences(int[] arr) {
        int freq[] = new int[2001];

        for(int num: arr){
            freq[num + 1000]++;
        }

        BitSet seen = new BitSet();

        for(int f: freq){
            if(f == 0) continue;
            if(seen.get(f)) return false;
            seen.set(f);
        }
        
        return true;
    }

    public static void main(String[] args) {
        int[] test1 = {1, 2, 2, 1, 1, 3};
        int[] test2 = {1, 2};
        int[] test3 = {-3, 0, 1, -3, 1, 1, 1, -3, 10, 0};

        System.out.println(uniqueOccurrences(test1)); // true
        System.out.println(uniqueOccurrences(test2)); // false
        System.out.println(uniqueOccurrences(test3)); // true
    }
}
