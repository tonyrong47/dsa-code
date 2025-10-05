// File: quick_sort.go

package main

import "fmt"

func partition(arr []int, low, high int) int {
	pivot := arr[high]
	i := low - 1

	for j := low; j < high; j++ {
		if arr[j] <= pivot {
			i++
			arr[i], arr[j] = arr[j], arr[i]
		}
	}
	arr[i+1], arr[high] = arr[high], arr[i+1]
	return i + 1
}

func quickSort(arr []int, low, high int) {
	if low < high {
		pi := partition(arr, low, high)
		quickSort(arr, low, pi-1)
		quickSort(arr, pi+1, high)
	}
}

func main() {
	data := []int{10, 7, 8, 9, 1, 5}
	
	fmt.Println("Original:", data)
	quickSort(data, 0, len(data)-1)
	fmt.Println("Sorted:", data)
}