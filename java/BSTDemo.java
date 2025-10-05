import java.util.*;

// Node class for BST
class BSTNode {
    int data;
    BSTNode left, right;

    BSTNode(int value) {
        data = value;
        left = right = null;
    }
}

class BSTViews {
    BSTNode root;

    BSTViews() { root = null; }

    // Insert
    void insert(int value) {
        root = insertRec(root, value);
    }

    BSTNode insertRec(BSTNode node, int value) {
        if (node == null) return new BSTNode(value);
        if (value < node.data) node.left = insertRec(node.left, value);
        else if (value > node.data) node.right = insertRec(node.right, value);
        return node;
    }

    // Traversals
    void preorder(BSTNode node) {
        if (node == null) return;
        System.out.print(node.data + " ");
        preorder(node.left);
        preorder(node.right);
    }

    void inorder(BSTNode node) {
        if (node == null) return;
        inorder(node.left);
        System.out.print(node.data + " ");
        inorder(node.right);
    }

    void postorder(BSTNode node) {
        if (node == null) return;
        postorder(node.left);
        postorder(node.right);
        System.out.print(node.data + " ");
    }

    void levelOrder() {
        if (root == null) return;
        Queue<BSTNode> q = new LinkedList<>();
        q.add(root);
        while (!q.isEmpty()) {
            BSTNode temp = q.poll();
            System.out.print(temp.data + " ");
            if (temp.left != null) q.add(temp.left);
            if (temp.right != null) q.add(temp.right);
        }
    }

    // Left View
    void leftView() {
        if (root == null) return;
        Queue<BSTNode> q = new LinkedList<>();
        q.add(root);
        while (!q.isEmpty()) {
            int n = q.size();
            for (int i = 1; i <= n; i++) {
                BSTNode temp = q.poll();
                if (i == 1) System.out.print(temp.data + " ");
                if (temp.left != null) q.add(temp.left);
                if (temp.right != null) q.add(temp.right);
            }
        }
    }

    // Right View
    void rightView() {
        if (root == null) return;
        Queue<BSTNode> q = new LinkedList<>();
        q.add(root);
        while (!q.isEmpty()) {
            int n = q.size();
            for (int i = 1; i <= n; i++) {
                BSTNode temp = q.poll();
                if (i == n) System.out.print(temp.data + " ");
                if (temp.left != null) q.add(temp.left);
                if (temp.right != null) q.add(temp.right);
            }
        }
    }

    // Top View
    void topView() {
        if (root == null) return;
        class Pair { BSTNode node; int hd; Pair(BSTNode n, int h) {node=n;hd=h;} }
        Queue<Pair> q = new LinkedList<>();
        Map<Integer,Integer> map = new TreeMap<>();
        q.add(new Pair(root, 0));
        while (!q.isEmpty()) {
            Pair p = q.poll();
            if (!map.containsKey(p.hd)) map.put(p.hd, p.node.data);
            if (p.node.left != null) q.add(new Pair(p.node.left, p.hd-1));
            if (p.node.right != null) q.add(new Pair(p.node.right, p.hd+1));
        }
        for (int val : map.values()) System.out.print(val + " ");
    }

    // Bottom View
    void bottomView() {
        if (root == null) return;
        class Pair { BSTNode node; int hd; Pair(BSTNode n,int h){node=n;hd=h;} }
        Queue<Pair> q = new LinkedList<>();
        Map<Integer,Integer> map = new TreeMap<>();
        q.add(new Pair(root,0));
        while(!q.isEmpty()){
            Pair p = q.poll();
            map.put(p.hd, p.node.data);
            if(p.node.left!=null) q.add(new Pair(p.node.left,p.hd-1));
            if(p.node.right!=null) q.add(new Pair(p.node.right,p.hd+1));
        }
        for(int val: map.values()) System.out.print(val + " ");
    }
}

// Demo to prove correctness
public class BSTDemo {
    public static void main(String[] args) {
        BSTViews bst = new BSTViews();
        int[] values = {50, 30, 20, 40, 70, 60, 80};
        for(int val : values) bst.insert(val);

        System.out.println("BST Views:");
        System.out.print("Preorder: "); bst.preorder(bst.root); System.out.println();
        System.out.print("Inorder: "); bst.inorder(bst.root); System.out.println();
        System.out.print("Postorder: "); bst.postorder(bst.root); System.out.println();
        System.out.print("Level-order: "); bst.levelOrder(); System.out.println();
        System.out.print("Left View: "); bst.leftView(); System.out.println();
        System.out.print("Right View: "); bst.rightView(); System.out.println();
        System.out.print("Top View: "); bst.topView(); System.out.println();
        System.out.print("Bottom View: "); bst.bottomView(); System.out.println();
    }
}
