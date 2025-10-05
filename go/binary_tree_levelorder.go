package main

import (
	"fmt"
)

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

// Level Order Traversal (BFS)
func levelOrder(root *Node) {
	if root == nil {
		return
	}
	queue := []*Node{root}

	for len(queue) > 0 {
		curr := queue[0]
		queue = queue[1:] // dequeue
		fmt.Printf("%d ", curr.data)

		if curr.left != nil {
			queue = append(queue, curr.left)
		}
		if curr.right != nil {
			queue = append(queue, curr.right)
		}
	}
}

func main() {
	var root *Node
	values := []int{10, 5, 20, 3, 7, 15, 25}

	for _, v := range values {
		root = insert(root, v)
	}

	fmt.Print("Level Order Traversal: ")
	levelOrder(root)
	fmt.Println()
}
