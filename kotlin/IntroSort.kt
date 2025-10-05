import java.util.Scanner
import kotlin.math.floor
import kotlin.math.log2

/**
 * Main entry point for the Introsort algorithm.
 * It calculates the depth limit and calls the recursive sorter.
 *
 * @param arr The array to be sorted.
 */
fun introsort(arr: IntArray) {
    if (arr.isEmpty()) return
    val depthLimit = (2 * floor(log2(arr.size.toDouble()))).toInt()
    introsortRecursive(arr, 0, arr.size - 1, depthLimit)
}

/**
 * The core recursive function for Introsort.
 * It switches to Heap Sort if recursion depth is exceeded,
 * and to Insertion Sort for small partitions.
 *
 * @param arr The array to sort.
 * @param begin The starting index of the partition.
 * @param end The ending index of the partition.
 * @param depthLimit The maximum recursion depth.
 */
private fun introsortRecursive(arr: IntArray, begin: Int, end: Int, depthLimit: Int) {
    if (end - begin <= 16) {
        insertionSort(arr, begin, end)
        return
    }

    if (depthLimit == 0) {
        heapSort(arr, begin, end)
        return
    }

    val pivotIndex = partition(arr, begin, end)
    introsortRecursive(arr, begin, pivotIndex - 1, depthLimit - 1)
    introsortRecursive(arr, pivotIndex + 1, end, depthLimit - 1)
}

/**
 * Partitions the array for Quick Sort.
 * Uses the last element as the pivot.
 *
 * @param arr The array to partition.
 * @param low The starting index.
 * @param high The ending index.
 * @return The index of the pivot after partitioning.
 */
private fun partition(arr: IntArray, low: Int, high: Int): Int {
    val pivot = arr[high]
    var i = low - 1
    for (j in low until high) {
        if (arr[j] <= pivot) {
            i++
            arr.swap(i, j)
        }
    }
    arr.swap(i + 1, high)
    return i + 1
}

/**
 * Sorts a small partition of the array using Insertion Sort.
 *
 * @param arr The array containing the partition.
 * @param left The starting index of the partition.
 * @param right The ending index of the partition.
 */
private fun insertionSort(arr: IntArray, left: Int, right: Int) {
    for (i in left + 1..right) {
        val key = arr[i]
        var j = i - 1
        while (j >= left && arr[j] > key) {
            arr[j + 1] = arr[j]
            j--
        }
        arr[j + 1] = key
    }
}

/**
 * Sorts a partition of the array using Heap Sort.
 *
 * @param arr The array containing the partition.
 * @param begin The starting index of the partition.
 * @param end The ending index of the partition.
 */
private fun heapSort(arr: IntArray, begin: Int, end: Int) {
    val n = end - begin + 1
    // Build heap (rearrange array)
    for (i in n / 2 - 1 downTo 0) {
        heapify(arr, n, i, begin)
    }

    // One by one extract an element from heap
    for (i in n - 1 downTo 0) {
        // Move current root to end
        arr.swap(begin, begin + i)
        // call max heapify on the reduced heap
        heapify(arr, i, 0, begin)
    }
}

/**
 * Helper function to heapify a subtree rooted with node i which is an index in arr[].
 *
 * @param arr The array.
 * @param n The size of the heap.
 * @param i The root of the subtree.
 * @param offset The offset for the start of the array partition.
 */
private fun heapify(arr: IntArray, n: Int, i: Int, offset: Int) {
    var largest = i
    val left = 2 * i + 1
    val right = 2 * i + 2

    if (left < n && arr[offset + left] > arr[offset + largest]) {
        largest = left
    }

    if (right < n && arr[offset + right] > arr[offset + largest]) {
        largest = right
    }

    if (largest != i) {
        arr.swap(offset + i, offset + largest)
        heapify(arr, n, largest, offset)
    }
}

/**
 * Swaps two elements in an IntArray.
 */
private fun IntArray.swap(i: Int, j: Int) {
    val temp = this[i]
    this[i] = this[j]
    this[j] = temp
}


/**
 * The main function to demonstrate the introsort functionality interactively.
 */
fun main() {
    val scanner = Scanner(System.`in`)

    println("--- Interactive Introsort in Kotlin ---")
    print("Enter the number of elements in the array: ")
    val n = scanner.nextInt()

    if (n <= 0) {
        println("Array size must be positive. Exiting.")
        return
    }

    val arr = IntArray(n)
    println("Enter the elements of the array:")
    for (i in 0 until n) {
        print("Element ${i + 1}: ")
        arr[i] = scanner.nextInt()
    }

    println("\nOriginal array: ${arr.joinToString(separator = ", ", prefix = "[", postfix = "]")}")

    introsort(arr)

    println("Sorted array:   ${arr.joinToString(separator = ", ", prefix = "[", postfix = "]")}")

    scanner.close()
}
