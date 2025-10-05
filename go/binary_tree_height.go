package main

import "fmt"

type Node struct {
	data  int
	left  *Node
	right *Node
}

// Insert node (BST insert)
func insert(root *Node, val int) *Node {
	if root == nil {
		return &Node{data: val}
	}
	if val < root.data {
		root.left = insert(root.left, val)
	} else {
		root.right = insert(root.right, val)
	}
	return root
}

// Find height of binary tree
func height(root *Node) int {
	if root == nil {
		return 0
	}
	leftHeight := height(root.left)
	rightHeight := height(root.right)

	if leftHeight > rightHeight {
		return leftHeight + 1
	}
	return rightHeight + 1
}

func main() {
	var root *Node
	values := []int{10, 5, 20, 3, 7, 15}

	for _, v := range values {
		root = insert(root, v)
	}

	fmt.Println("Height of tree:", height(root))
}
