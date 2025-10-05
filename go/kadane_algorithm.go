package main

import (
	"fmt"
	"math"
)

func kadane(arr []int) int {
	maxSum := math.MinInt32
	currentSum := 0

	for _, value := range arr {
		currentSum = max(value, currentSum+value)
		maxSum = max(maxSum, currentSum)
	}

	return maxSum
}

// helper function
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func main() {
	arr := []int{-2, 1, -3, 4, -1, 2, 1, -5, 4}
	fmt.Println("Array:", arr)

	result := kadane(arr)
	fmt.Println("Maximum Subarray Sum:", result)
}
