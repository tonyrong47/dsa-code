import java.util.Scanner

/**
 * Sorts an array using the merge sort algorithm.
 *
 * @param arr The array to be sorted.
 */
fun mergeSort(arr: IntArray) {
    if (arr.size <= 1) {
        return // Base case: array is already sorted or empty
    }

    // Find the middle of the array
    val middle = arr.size / 2
    
    // Split the array into two halves
    val left = arr.sliceArray(0 until middle)
    val right = arr.sliceArray(middle until arr.size)

    // Recursively sort both halves
    mergeSort(left)
    mergeSort(right)

    // Merge the sorted halves back into the original array
    merge(arr, left, right)
}

/**
 * Merges two sorted subarrays into a single sorted array.
 *
 * @param arr   The main array to be modified.
 * @param left  The sorted left subarray.
 * @param right The sorted right subarray.
 */
fun merge(arr: IntArray, left: IntArray, right: IntArray) {
    var i = 0 // Initial index for the left subarray
    var j = 0 // Initial index for the right subarray
    var k = 0 // Initial index for the merged array (arr)

    // Merge elements from left and right arrays in sorted order
    while (i < left.size && j < right.size) {
        if (left[i] <= right[j]) {
            arr[k] = left[i]
            i++
        } else {
            arr[k] = right[j]
            j++
        }
        k++
    }

    // Copy any remaining elements from the left subarray
    while (i < left.size) {
        arr[k] = left[i]
        i++
        k++
    }

    // Copy any remaining elements from the right subarray
    while (j < right.size) {
        arr[k] = right[j]
        j++
        k++
    }
}

/**
 * The main function to demonstrate the merge sort functionality interactively.
 */
fun main() {
    val scanner = Scanner(System.`in`)

    println("--- Interactive Merge Sort in Kotlin ---")
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

    mergeSort(arr)

    println("Sorted array:   ${arr.joinToString(separator = ", ", prefix = "[", postfix = "]")}")
    
    scanner.close()
}
