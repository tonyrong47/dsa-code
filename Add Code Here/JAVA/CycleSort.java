import java.util.Scanner;
import java.util.Arrays;

/**
 * 🚀 Cycle Sort Implementation
 * 
 * Sorts an array of distinct integers (1 to n) using Cycle Sort.
 * Validates input and handles errors gracefully.
 * 
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 * 
 * Example:
 * Input: 3 1 5 4 2
 * Output: 1 2 3 4 5
 * 
 * Author: Prince Yadav
 * Version: 2.0
 */
public class CycleSort {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter number of elements (distinct numbers 1 to n):");
        int n = sc.nextInt();
        if (n <= 0) {
            System.out.println("Error: Number of elements must be positive.");
            sc.close();
            return;
        }

        int[] arr = new int[n];
        System.out.println("Enter elements in the array:");
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
            if (arr[i] < 1 || arr[i] > n) {
                System.out.println("Error: Elements must be distinct numbers from 1 to " + n);
                sc.close();
                return;
            }
        }

        cycleSort(arr);

        System.out.println("Sorted array:");
        for (int num : arr) {
            System.out.print(num + " ");
        }
        System.out.println();

        sc.close();
    }

    /**
     * Cycle Sort algorithm
     * Sorts an array of distinct integers 1 to n
     * @param arr Input array
     */
    public static void cycleSort(int[] arr) {
        for (int i = 0; i < arr.length; i++) {
            while (arr[i] != i + 1) {
                int correct = arr[i] - 1;
                if (arr[correct] == arr[i]) break; // Prevent infinite loop
                int temp = arr[i];
                arr[i] = arr[correct];
                arr[correct] = temp;
            }
        }
    }

    /**
     * Utility method for testing
     * @param arr input array
     * @return sorted array (copy)
     */
    public static int[] sortArray(int[] arr) {
        int[] copy = Arrays.copyOf(arr, arr.length);
        cycleSort(copy);
        return copy;
    }
}
