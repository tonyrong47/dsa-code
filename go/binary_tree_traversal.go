package main

import "fmt"

// Node structure
type Node struct {

	value int

	data  int

	left  *Node
	right *Node
}


// Pre-order traversal: root -> left -> right
func preOrder(node *Node) {
	if node != nil {
		fmt.Print(node.value, " ")
		preOrder(node.left)
		preOrder(node.right)
	}
}

// In-order traversal: left -> root -> right
func inOrder(node *Node) {
	if node != nil {
		inOrder(node.left)
		fmt.Print(node.value, " ")
		inOrder(node.right)
	}
}

// Post-order traversal: left -> right -> root
func postOrder(node *Node) {
	if node != nil {
		postOrder(node.left)
		postOrder(node.right)
		fmt.Print(node.value, " ")
	}
}

// Level-order traversal (BFS)
func levelOrder(root *Node) {
	if root == nil {
		return
	}

	queue := []*Node{root}

	for len(queue) > 0 {
		current := queue[0]
		queue = queue[1:]
		fmt.Print(current.value, " ")

		if current.left != nil {
			queue = append(queue, current.left)
		}
		if current.right != nil {
			queue = append(queue, current.right)
		}

// Insert into binary tree (simple BST insert)
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

// Inorder Traversal
func inorder(root *Node) {
	if root != nil {
		inorder(root.left)
		fmt.Printf("%d ", root.data)
		inorder(root.right)
	}
}

// Preorder Traversal
func preorder(root *Node) {
	if root != nil {
		fmt.Printf("%d ", root.data)
		preorder(root.left)
		preorder(root.right)
	}
}

// Postorder Traversal
func postorder(root *Node) {
	if root != nil {
		postorder(root.left)
		postorder(root.right)
		fmt.Printf("%d ", root.data)

	}
}

func main() {

	// Create a simple binary tree
	root := &Node{value: 1}
	root.left = &Node{value: 2}
	root.right = &Node{value: 3}
	root.left.left = &Node{value: 4}
	root.left.right = &Node{value: 5}

	fmt.Print("Pre-order: ")
	preOrder(root)
	fmt.Println()

	fmt.Print("In-order: ")
	inOrder(root)
	fmt.Println()

	fmt.Print("Post-order: ")
	postOrder(root)
	fmt.Println()

	fmt.Print("Level-order: ")
	levelOrder(root)

	var root *Node
	values := []int{10, 5, 20, 3, 7, 15, 25}

	for _, v := range values {
		root = insert(root, v)
	}

	fmt.Print("Inorder: ")
	inorder(root)
	fmt.Println()

	fmt.Print("Preorder: ")
	preorder(root)
	fmt.Println()

	fmt.Print("Postorder: ")
	postorder(root)

	fmt.Println()
}
