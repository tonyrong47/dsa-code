import java.util.Scanner

/**
 * Sorts an array using the bubble sort algorithm.
 *
 * @param arr The array to be sorted.
 */
fun bubbleSort(arr: IntArray) {
    val n = arr.size
    var swapped: Boolean
    // The outer loop runs from the first element to the second-to-last element.
    // After each pass of the outer loop, the largest unsorted element "bubbles up" to its correct position.
    for (i in 0 until n - 1) {
        swapped = false
        // The inner loop compares adjacent elements and swaps them if they are in the wrong order.
        // The range of the inner loop decreases with each pass, as the largest elements are already in place.
        for (j in 0 until n - i - 1) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j+1]
                val temp = arr[j]
                arr[j] = arr[j + 1]
                arr[j + 1] = temp
                swapped = true
            }
        }
        // If no two elements were swapped by the inner loop, the array is already sorted.
        if (!swapped) {
            break
        }
    }
}

/**
 * The main function to demonstrate the bubble sort functionality interactively.
 */
fun main() {
    val scanner = Scanner(System.`in`)

    println("--- Interactive Bubble Sort in Kotlin ---")
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

    bubbleSort(arr)

    println("Sorted array:   ${arr.joinToString(separator = ", ", prefix = "[", postfix = "]")}")

    scanner.close()
}
