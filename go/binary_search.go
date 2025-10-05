package main

import "fmt"

func binarySearch(arr []int, target int) int {
	low := 0
	high := len(arr) - 1

	for low <= high {
		mid := low + (high-low)/2 // Avoids overflow
		
		if arr[mid] == target {
			return mid
		} else if arr[mid] < target {
			low = mid + 1
		} else {
			high = mid - 1
		}
	}
	return -1 // Not found
}

// Example
func main() {
	sortedArr := []int{2, 5, 8, 12, 16, 23, 38, 56, 72, 91}
	t1 := 23
	t2 := 10

	index1 := binarySearch(sortedArr, t1)
	index2 := binarySearch(sortedArr, t2)

	fmt.Printf("Searching for %d in array: %v\n", t1, sortedArr)
	fmt.Printf("Found %d at index: %d\n", t1, index1)
	
	fmt.Printf("Searching for %d in array: %v\n", t2, sortedArr)
	fmt.Printf("Found %d at index: %d\n", t2, index2)
}