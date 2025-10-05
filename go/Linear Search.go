package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Linear search function
func linearSearch(arr []int, target int) int {
	for i, value := range arr {
		if value == target {
			return i
		}
	}
	return -1
}

func main() {
	reader := bufio.NewReader(os.Stdin)

	// Input array
	fmt.Print("Enter numbers separated by space: ")
	input, _ := reader.ReadString('\n')
	input = strings.TrimSpace(input)
	strNums := strings.Split(input, " ")

	var arr []int
	for _, str := range strNums {
		num, err := strconv.Atoi(str)
		if err != nil {
			fmt.Println("Invalid input, please enter integers only.")
			return
		}
		arr = append(arr, num)
	}

	// Input target number
	fmt.Print("Enter the number to search: ")
	targetStr, _ := reader.ReadString('\n')
	targetStr = strings.TrimSpace(targetStr)
	target, err := strconv.Atoi(targetStr)
	if err != nil {
		fmt.Println("Invalid input, please enter an integer.")
		return
	}

	// Perform search
	index := linearSearch(arr, target)

	fmt.Printf("\nArray: %v\n", arr)
	if index != -1 {
		fmt.Printf("✅ Found %d at position %d (index %d)\n", target, index+1, index)
	} else {
		fmt.Printf("❌ Sorry, %d was not found in the array.\n", target)
	}
}
