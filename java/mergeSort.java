import java.util.Arrays;
import java.util.Scanner;

/**
 * A class containing the implementation of the Merge Sort algorithm.
 */
public class MergeSort {

    /**
     * The main method that sorts an array using the merge sort algorithm.
     *
     * @param arr The array to be sorted.
     */
    public void sort(int[] arr) {
        if (arr == null || arr.length <= 1) {
            return; // Already sorted or nothing to sort
        }
        mergeSort(arr, 0, arr.length - 1);
    }

    /**
     * A recursive helper method that divides the array and calls the merge method.
     *
     * @param arr   The array containing the subarrays to be sorted.
     * @param left  The starting index of the subarray.
     * @param right The ending index of the subarray.
     */
    private void mergeSort(int[] arr, int left, int right) {
        if (left < right) {
            // Find the middle point to divide the array into two halves
            int middle = left + (right - left) / 2;

            // Recursively sort the first and second halves
            mergeSort(arr, left, middle);
            mergeSort(arr, middle + 1, right);

            // Merge the sorted halves
            merge(arr, left, middle, right);
        }
    }

    /**
     * Merges two sorted subarrays into a single sorted subarray.
     * The first subarray is arr[left..middle].
     * The second subarray is arr[middle+1..right].
     *
     * @param arr    The main array.
     * @param left   The starting index of the first subarray.
     * @param middle The ending index of the first subarray.
     * @param right  The ending index of the second subarray.
     */
    private void merge(int[] arr, int left, int middle, int right) {
        // Find sizes of two subarrays to be merged
        int n1 = middle - left + 1;
        int n2 = right - middle;

        // Create temporary arrays
        int[] leftArray = new int[n1];
        int[] rightArray = new int[n2];

        // Copy data to temporary arrays
        System.arraycopy(arr, left, leftArray, 0, n1);
        System.arraycopy(arr, middle + 1, rightArray, 0, n2);

        // Initial indexes of first and second subarrays
        int i = 0, j = 0;

        // Initial index of the merged subarray
        int k = left;

        // Merge the temporary arrays back into the original array arr[left..right]
        while (i < n1 && j < n2) {
            if (leftArray[i] <= rightArray[j]) {
                arr[k] = leftArray[i];
                i++;
            } else {
                arr[k] = rightArray[j];
                j++;
            }
            k++;
        }

        // Copy remaining elements of leftArray[], if any
        while (i < n1) {
            arr[k] = leftArray[i];
            i++;
            k++;
        }

        // Copy remaining elements of rightArray[], if any
        while (j < n2) {
            arr[k] = rightArray[j];
            j++;
            k++;
        }
    }

    /**
     * The main method to demonstrate the merge sort functionality interactively.
     */
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        MergeSort sorter = new MergeSort();

        System.out.println("--- Interactive Merge Sort ---");
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

