// contributed by Tushar Kumar 
// GitHub - https://github.com/Tusharkumar200

package Arrays;

import java.util.HashSet;
import java.util.Set;

public class Longest_Consecutive_Sequence_in_an_Array {

    // Brute Force

    public static boolean linearSearch(int[] a, int num) {

        for (int i : a) {

            if (i == num)
                return true;
        }
        return false;
    }

    public static int longestSuccessiveElements(int[] a) {

        int longest = 1;

        for (int i : a) {
            int x = i;
            int cnt = 1;

            while (linearSearch(a, x + 1) == true) {

                x += 1;
                cnt += 1;
            }

            longest = Math.max(cnt, longest);
        }
        return longest;
    }

    // Optimal Approched

    public static int longestSuccessiveElementsOptimal(int[] a) {

        int n = a.length;
        if (n == 0)
            return 0;

        int longest = 1;

        Set<Integer> set = new HashSet<>();

        for (int i : a) {
            set.add(i);
        }

        for (int it : set) {

            int cnt = 1;
            int x = it;

            if (!set.contains(it - 1)) {

                while (set.contains(x + 1)) {

                    x = x + 1;
                    cnt = cnt + 1;
                }

                longest = Math.max(longest, cnt);
            }
        }
        return longest;
    }

    public static void main(String[] args) {
        int[] a = { 100, 200, 1, 2, 3, 4 };
        // int ans = longestSuccessiveElements(a);
        int ans = longestSuccessiveElementsOptimal(a);

        System.out.println("The longest consecutive sequence is " + ans);
    }
}
