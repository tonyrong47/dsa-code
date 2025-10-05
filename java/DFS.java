import java.util.*;

public class Main {
    // Function to add an edge to the adjacency list
    public static void
    addEdge(ArrayList<ArrayList<Integer> > adj, int s,
            int t)
    {
        adj.get(s).add(t);
        adj.get(t).add(s);
    }

    // Recursive function for DFS traversal
    private static void
    dfsRec(ArrayList<ArrayList<Integer> > adj,
           boolean[] visited, int s, ArrayList<Integer> res)
    {
        visited[s] = true;
        res.add(s);

        // Recursively visit all adjacent vertices that are
        // not visited yet
        for (int i : adj.get(s)) {
            if (!visited[i]) {
                dfsRec(adj, visited, i, res);
            }
        }
    }

    // Main DFS function to perform DFS for the entire graph
    public static ArrayList<Integer>
    DFS(ArrayList<ArrayList<Integer> > adj)
    {
        boolean[] visited = new boolean[adj.size()];
        ArrayList<Integer> res = new ArrayList<>();

        // Loop through all vertices to handle disconnected
        // graphs
        for (int i = 0; i < adj.size(); i++) {
            if (!visited[i]) {
                dfsRec(adj, visited, i, res);
            }
        }

        return res;
    }

    public static void main(String[] args)
    {
        int V = 6;
        // Create an adjacency list for the graph
        ArrayList<ArrayList<Integer> > adj
            = new ArrayList<>();

        // Initialize adjacency list
        for (int i = 0; i < V; i++) {
            adj.add(new ArrayList<>());
        }

        // Define the edges of the graph
        int[][] edges
            = { { 1, 2 }, { 2, 0 }, { 0, 3 }, { 4, 5 } };

        // Populate the adjacency list with edges
        for (int[] e : edges) {
            addEdge(adj, e[0], e[1]);
        }

        // Perform DFS
        ArrayList<Integer> res = DFS(adj);

        // Print the DFS traversal result
        for (int num : res) {
            System.out.print(num + " ");
        }
    }
}


// Output
// 0 2 1 3 4 5 

// Time complexity: O(V + E). Note that the time complexity is same here because we visit every vertex at most once and every edge is traversed at most once (in directed) and twice in undirected.
// Auxiliary Space: O(V + E), since an extra visited array of size V is required, And stack size for recursive calls to dfsRec function.
