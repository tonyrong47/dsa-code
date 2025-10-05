import java.util.Arrays;
import java.util.Scanner;

/**
 * A class containing the implementation of the Quick Sort algorithm.
 */
public class QuickSort {

    /**
     * The main method that sorts an array using the quick sort algorithm.
     *
     * @param arr The array to be sorted.
     */
    public void sort(int[] arr) {
        if (arr == null || arr.length == 0) {
            return;
        }
        quickSort(arr, 0, arr.length - 1);
    }

    /**
     * A recursive helper method to sort the array.
     *
     * @param arr  The array to be sorted.
     * @param low  The starting index.
     * @param high The ending index.
     */
    private void quickSort(int[] arr, int low, int high) {
        if (low < high) {
            // pi is partitioning index, arr[pi] is now at right place
            int pi = partition(arr, low, high);

            // Recursively sort elements before partition and after partition
            quickSort(arr, low, pi - 1);
            quickSort(arr, pi + 1, high);
        }
    }

    /**
     * This method takes the last element as pivot, places the pivot element at its
     * correct position in the sorted array, and places all smaller (smaller than pivot)
     * elements to the left of the pivot and all greater elements to the right of the pivot.
     *
     * @param arr  The array to be partitioned.
     * @param low  The starting index.
     * @param high The ending index.
     * @return The partitioning index.
     */
    private int partition(int[] arr, int low, int high) {
        // Choose the rightmost element as pivot
        int pivot = arr[high];

        // Index of smaller element
        int i = (low - 1);

        for (int j = low; j < high; j++) {
            // If current element is smaller than or equal to pivot
            if (arr[j] <= pivot) {
                i++;

                // Swap arr[i] and arr[j]
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }

        // Swap arr[i+1] and arr[high] (or pivot)
        int temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;

        return i + 1;
    }

    /**
     * The main method to demonstrate the quick sort functionality interactively.
     */
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        QuickSort sorter = new QuickSort();

        System.out.println("--- Interactive Quick Sort ---");
        System.out.print("Enter the number of elements in the array: ");
        int n = scanner.nextInt();

        if (n <= 0) {
            System.out.println("Array size must be positive. Exiting.");
            scanner.close();
            return;
        }

        int[] arr = new int[n];
        System.out.println("Enter the elements of the array:");
        for (int i = 0; i < n; i++) {
            System.out.print("Element " + (i + 1) + ": ");
            arr[i] = scanner.nextInt();
        }

        System.out.println("\nOriginal array: " + Arrays.toString(arr));

        sorter.sort(arr);

        System.out.println("Sorted array:   " + Arrays.toString(arr));

        scanner.close();
    }
}
