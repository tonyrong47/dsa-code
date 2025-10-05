import java.util.Arrays;

public class ArrayUtils {

    public static int findMax(int[] arr) {
        if (arr == null || arr.length == 0)
            throw new IllegalArgumentException("Array is empty or null");
        int max = arr[0];
        for (int num : arr) if (num > max) max = num;
        return max;
    }

    public static int findMin(int[] arr) {
        if (arr == null || arr.length == 0)
            throw new IllegalArgumentException("Array is empty or null");
        int min = arr[0];
        for (int num : arr) if (num < min) min = num;
        return min;
    }

    public static int sum(int[] arr) {
        if (arr == null) return 0;
        int total = 0;
        for (int num : arr) total += num;
        return total;
    }

    public static double average(int[] arr) {
        if (arr == null || arr.length == 0)
            throw new IllegalArgumentException("Array is empty or null");
        return (double) sum(arr) / arr.length;
    }

    public static void reverse(int[] arr) {
        if (arr == null) return;
        int left = 0, right = arr.length - 1;
        while (left < right) {
            int temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
            left++;
            right--;
        }
    }

    public static boolean contains(int[] arr, int target) {
        if (arr == null) return false;
        for (int num : arr) if (num == target) return true;
        return false;
    }

    public static String toString(int[] arr) {
        return Arrays.toString(arr);
    }
}
