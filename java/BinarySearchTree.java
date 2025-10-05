/**

 * BinarySearchTree class: Implements a Binary Search Tree (BST)
 * with insertion and deletion operations, utilizing the Node structure
 * from BinaryTree.
 */
public class BinarySearchTree {

    // Reuse the Node structure defined in BinaryTree.java
    public static class Node extends BinaryTree.Node {
        public Node(int data) {
            super(data);
        }
    }

    public Node root;

    public BinarySearchTree() {
        this.root = null;
    }

    // --- 1. Insertion Operation ---

    public void insert(int data) {
        root = insertRec(root, data);
    }

    // A recursive function to insert a new key in BST
    private Node insertRec(Node root, int data) {
        // If the tree is empty, return a new node
        if (root == null) {
            root = new Node(data);
            return root;
        }

        // Otherwise, recur down the tree
        if (data < root.data) {
            root.left = insertRec((Node) root.left, data);
        } else if (data > root.data) {
            root.right = insertRec((Node) root.right, data);
        }

        // Return the (unchanged) node pointer
        return root;
    }

    // --- 2. Deletion Operation ---

    public void delete(int data) {
        root = deleteRec(root, data);
    }

    // A recursive function to delete a key in BST
    private Node deleteRec(Node root, int data) {
        // Base case: If the tree is empty or the key is not found

 * Implements a Binary Search Tree (BST) with insertion, deletion, and traversal operations.
 * It inherits properties from the BinaryTree class.
 */
public class BinarySearchTree extends BinaryTree {

    /**
     * Inserts a new key into the BST.
     * @param key The data to insert.
     */
    public void insert(int key) {
        root = insertRec(root, key);
    }

    /**
     * A recursive utility function to insert a new key in the BST.
     * @param root The current root of the subtree.
     * @param key The data to insert.
     * @return The node pointer (after insertion).
     */
    private Node insertRec(Node root, int key) {
        if (root == null) {
            root = new Node(key);
            return root;
        }
        if (key < root.data) {
            root.left = insertRec(root.left, key);
        } else if (key > root.data) {
            root.right = insertRec(root.right, key);
        }
        return root;
    }

    /**
     * Deletes a key from the BST.
     * @param key The data to delete.
     */
    public void delete(int key) {
        root = deleteRec(root, key);
    }

    /**
     * A recursive utility function to delete a key from the BST.
     * @param root The current root of the subtree.
     * @param key The data to delete.
     * @return The root of the modified subtree.
     */
    private Node deleteRec(Node root, int key) {

        if (root == null) {
            return root;
        }


        // Recur down the tree
        if (data < root.data) {
            root.left = deleteRec((Node) root.left, data);
        } else if (data > root.data) {
            root.right = deleteRec((Node) root.right, data);
        }
        // If data is the same as root's data, then this is the node to be deleted
        else {
            // Case 1: Node with only one child or no child
            if (root.left == null) {
                return (Node) root.right;
            } else if (root.right == null) {
                return (Node) root.left;
            }

            // Case 2: Node with two children: Get the inorder successor
            // (smallest in the right subtree)
            root.data = minValue((Node) root.right);

            // Delete the inorder successor
            root.right = deleteRec((Node) root.right, root.data);

        if (key < root.data) {
            root.left = deleteRec(root.left, key);
        } else if (key > root.data) {
            root.right = deleteRec(root.right, key);
        } else {
            // Node with only one child or no child
            if (root.left == null) {
                return root.right;
            } else if (root.right == null) {
                return root.left;
            }

            // Node with two children: Get the inorder successor (smallest in the right subtree)
            root.data = minValue(root.right);

            // Delete the inorder successor
            root.right = deleteRec(root.right, root.data);

        }

        return root;
    }

    // Helper function to find the minimum value node in a BST
    private int minValue(Node root) {
        int minValue = root.data;
        while (root.left != null) {
            minValue = root.left.data;
            root = (Node) root.left;
        }
        return minValue;
    }

    // --- 3. Traversal (Can call BinaryTree methods, but re-implementing for completeness) ---

    public void inorderTraversal() {
        System.out.print("Inorder Traversal: ");
        inorderRec(root);
        System.out.println();
    }

    private void inorderRec(Node root) {
        if (root != null) {
            inorderRec((Node) root.left);
            System.out.print(root.data + " ");
            inorderRec((Node) root.right);
        }

    /**
     * Finds the minimum value in a given subtree.
     * @param root The root of the subtree.
     * @return The minimum value.
     */
    private int minValue(Node root) {
        int minv = root.data;
        while (root.left != null) {
            minv = root.left.data;
            root = root.left;
        }
        return minv;

    }
}
