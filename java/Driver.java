import java.util.List;

/**
 * Driver class for testing both BinaryTree and BinarySearchTree implementations.
 */
public class Driver {

    public static void main(String[] args) {
        System.out.println("--- Binary Tree (Generic) Implementation Test ---");
        testBinaryTree();
        
        System.out.println("\n--- Binary Search Tree Implementation Test ---");
        testBinarySearchTree();
    }

    private static void testBinaryTree() {
        // Create a generic Binary Tree (not necessarily a BST)
        BinaryTree tree = new BinaryTree();
        tree.root = new BinaryTree.Node(1);
        tree.root.left = new BinaryTree.Node(2);
        tree.root.right = new BinaryTree.Node(3);
        tree.root.left.left = new BinaryTree.Node(4);
        tree.root.left.right = new BinaryTree.Node(5);
        tree.root.right.left = new BinaryTree.Node(6);
        tree.root.right.right = new BinaryTree.Node(7);
        tree.root.left.right.right = new BinaryTree.Node(8); 
        // Structure:
        //        1
        //      /   \
        //     2     3
        //    / \   / \
        //   4   5 6   7
        //        \
        //         8

        System.out.print("Preorder Traversal: ");
        tree.preorder(tree.root);
        System.out.println();

        System.out.print("Inorder Traversal: ");
        tree.inorder(tree.root);
        System.out.println();

        System.out.print("Postorder Traversal: ");
        tree.postorder(tree.root);
        System.out.println();

        // Testing all View Methods
        List<Integer> topView = tree.topView();
        System.out.println("Top View:    " + topView); // Expected: 4, 2, 1, 3, 7

        List<Integer> bottomView = tree.bottomView();
        System.out.println("Bottom View: " + bottomView); // Expected: 4, 2, 8, 6, 7

        List<Integer> leftView = tree.leftView();
        System.out.println("Left View:   " + leftView); // Expected: 1, 2, 4, 8

        List<Integer> rightView = tree.rightView();
        System.out.println("Right View:  " + rightView); // Expected: 1, 3, 7, 8
    }

    private static void testBinarySearchTree() {
        BinarySearchTree bst = new BinarySearchTree();
        
        // Insertion
        System.out.println("Inserting elements: 50, 30, 20, 40, 70, 60, 80...");
        bst.insert(50);
        bst.insert(30);
        bst.insert(20);
        bst.insert(40);
        bst.insert(70);
        bst.insert(60);
        bst.insert(80);
        
        // Structure:
        //        50
        //      /    \
        //     30     70
        //    / \   / \
        //   20 40 60 80

        bst.inorderTraversal(); // Inorder traversal of a BST should be sorted: 20 30 40 50 60 70 80

        // Deletion Test 1: Leaf Node (20)
        System.out.println("Deleting 20 (Leaf Node)...");
        bst.delete(20);
        bst.inorderTraversal(); // Expected: 30 40 50 60 70 80

        // Deletion Test 2: Node with two children (30)
        System.out.println("Deleting 30 (Node with 1 child, 40)..."); 
        // 30 is replaced by its successor, 40
        bst.delete(30);
        bst.inorderTraversal(); // Expected: 40 50 60 70 80
        
        // Demonstrate views on the BST (Need to cast the root to BinaryTree.Node to use view methods)
        BinaryTree bstAsTree = new BinaryTree();
        bstAsTree.root = bst.root; // Use the BST root for view methods

        System.out.println("\nViews on the modified BST:");
        System.out.println("Top View:    " + bstAsTree.topView());    // Expected: 40, 50, 70, 80
        System.out.println("Bottom View: " + bstAsTree.bottomView()); // Expected: 40, 50, 60, 80
        System.out.println("Left View:   " + bstAsTree.leftView());   // Expected: 50, 40
        System.out.println("Right View:  " + bstAsTree.rightView());  // Expected: 50, 70, 80
    }
}
