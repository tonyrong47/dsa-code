package tests.JAVA;
import static org.junit.jupiter.api.Assertions.*;
import org.junit.jupiter.api.Test;

class CycleSortTest {

    @Test
    void testBasicSorting() {
        int[] arr = {3, 1, 5, 4, 2};
        int[] sorted = {1, 2, 3, 4, 5};
        assertArrayEquals(sorted, CycleSort.sortArray(arr));
    }

    @Test
    void testAlreadySorted() {
        int[] arr = {1, 2, 3, 4, 5};
        assertArrayEquals(arr, CycleSort.sortArray(arr));
    }

    @Test
    void testReverseSorted() {
        int[] arr = {5, 4, 3, 2, 1};
        int[] sorted = {1, 2, 3, 4, 5};
        assertArrayEquals(sorted, CycleSort.sortArray(arr));
    }

    @Test
    void testSingleElement() {
        int[] arr = {1};
        assertArrayEquals(new int[]{1}, CycleSort.sortArray(arr));
    }

    @Test
    void testEmptyArray() {
        int[] arr = {};
        assertArrayEquals(new int[]{}, CycleSort.sortArray(arr));
    }

    @Test
    void testLargeArray() {
        int n = 1000;
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) arr[i] = n - i;
        int[] expected = new int[n];
        for (int i = 0; i < n; i++) expected[i] = i + 1;
        assertArrayEquals(expected, CycleSort.sortArray(arr));
    }
}
