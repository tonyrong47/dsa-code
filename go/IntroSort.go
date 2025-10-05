package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
)

// Introsort is the main entry point for the algorithm.
// It calculates the depth limit and calls the recursive sorter.
// arr: The slice of integers to be sorted.
func Introsort(arr []int) {
	if len(arr) == 0 {
		return
	}
	// Calculate depth limit: 2 * log2(n)
	depthLimit := int(2 * math.Log2(float64(len(arr))))
	introsortRecursive(arr, 0, len(arr)-1, depthLimit)
}

// introsortRecursive is the core recursive function for Introsort.
// It switches to Heap Sort if recursion depth is exceeded,
// and to Insertion Sort for small partitions.
// arr: The slice to sort.
// begin: The starting index of the partition.
// end: The ending index of the partition.
// depthLimit: The maximum recursion depth.
func introsortRecursive(arr []int, begin, end, depthLimit int) {
	size := end - begin + 1
	if size <= 16 {
		insertionSort(arr, begin, end)
		return
	}

	if depthLimit == 0 {
		heapSort(arr, begin, end)
		return
	}

	pivotIndex := partition(arr, begin, end)
	introsortRecursive(arr, begin, pivotIndex-1, depthLimit-1)
	introsortRecursive(arr, pivotIndex+1, end, depthLimit-1)
}

// partition rearranges the slice for Quick Sort using the Lomuto partition scheme.
// It uses the last element as the pivot.
// arr: The slice to partition.
// low: The starting index.
// high: The ending index.
// Returns the index of the pivot after partitioning.
func partition(arr []int, low, high int) int {
	pivot := arr[high]
	i := low - 1
	for j := low; j < high; j++ {
		if arr[j] <= pivot {
			i++
			arr[i], arr[j] = arr[j], arr[i] // Swap
		}
	}
	arr[i+1], arr[high] = arr[high], arr[i+1] // Swap pivot into place
	return i + 1
}

// insertionSort sorts a small partition of the slice.
// arr: The slice containing the partition.
// left: The starting index of the partition.
// right: The ending index of the partition.
func insertionSort(arr []int, left, right int) {
	for i := left + 1; i <= right; i++ {
		key := arr[i]
		j := i - 1
		for j >= left && arr[j] > key {
			arr[j+1] = arr[j]
			j--
		}
		arr[j+1] = key
	}
}

// heapSort sorts a partition of the slice using the Heap Sort algorithm.
// arr: The slice containing the partition.
// begin: The starting index of the partition.
// end: The ending index of the partition.
func heapSort(arr []int, begin, end int) {
	n := end - begin + 1
	offset := begin

	// Build heap (rearrange array)
	for i := n/2 - 1; i >= 0; i-- {
		heapify(arr, n, i, offset)
	}

	// One by one extract an element from heap
	for i := n - 1; i > 0; i-- {
		// Move current root to end
		arr[offset], arr[offset+i] = arr[offset+i], arr[offset]
		// call max heapify on the reduced heap
		heapify(arr, i, 0, offset)
	}
}

// heapify is a helper function to maintain the heap property.
// arr: The slice.
// n: The size of the heap.
// i: The root of the subtree.
// offset: The offset for the start of the slice partition.
func heapify(arr []int, n, i, offset int) {
	largest := i
	left := 2*i + 1
	right := 2*i + 2

	if left < n && arr[offset+left] > arr[offset+largest] {
		largest = left
	}

	if right < n && arr[offset+right] > arr[offset+largest] {
		largest = right
	}

	if largest != i {
		arr[offset+i], arr[offset+largest] = arr[offset+largest], arr[offset+i]
		heapify(arr, n, largest, offset)
	}
}

// main is the driver function that demonstrates introsort interactively.
func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Println("--- Interactive Introsort in Go ---")
	fmt.Print("Enter the elements of the array (space-separated): ")

	input, err := reader.ReadString('\n')
	if err != nil {
		fmt.Println("Error reading input:", err)
		return
	}
	input = strings.TrimSpace(input)

	if input == "" {
		fmt.Println("No input provided. Exiting.")
		return
	}

	parts := strings.Split(input, " ")
	arr := make([]int, 0, len(parts))

	for _, part := range parts {
		num, err := strconv.Atoi(part)
		if err != nil {
			fmt.Printf("Invalid input '%s'. Please enter numbers only. Exiting.\n", part)
			return
		}
		arr = append(arr, num)
	}

	fmt.Println("\nOriginal array:", arr)
	Introsort(arr)
	fmt.Println("Sorted array:  ", arr)
}
