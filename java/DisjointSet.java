/*
  Disjoint Set Union (Union-Find) in Java
  ----------------------------------------
  Features:
  - Path Compression (optimizes find operation)
  - Union by Rank (balances tree height)
  
  Time Complexity:
  - find(): O(α(N)) ~ constant
  - union(): O(α(N)) ~ constant
*/

class DisjointSet {
    int[] parent;
    int[] rank;

    // Constructor: initialize DSU for 'n' elements
    DisjointSet(int n) {
        parent = new int[n];
        rank = new int[n];
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    // Find with path compression
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); // compress path
        }
        return parent[x];
    }

    // Union by rank
    void union(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX == rootY) return; // already in same set

        if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }

    // Example usage
    public static void main(String[] args) {
        DisjointSet dsu = new DisjointSet(5);

        dsu.union(0, 2);
        dsu.union(4, 2);
        dsu.union(3, 1);

        // Should print "Connected"
        if (dsu.find(4) == dsu.find(0)) {
            System.out.println("Connected");
        } else {
            System.out.println("Not Connected");
        }

        // Should print "Not Connected"
        if (dsu.find(1) == dsu.find(0)) {
            System.out.println("Connected");
        } else {
            System.out.println("Not Connected");
        }
    }
}
