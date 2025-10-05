// BFS from given source s
import java.util.*;

class Main {

    // BFS from given source s
    static ArrayList<Integer> 
        bfsOfGraph(ArrayList<ArrayList<Integer>> adj, 
                int s, boolean[] visited, ArrayList<Integer> res) {

        // Create a queue for BFS
        Queue<Integer> q = new LinkedList<>();

        // Mark source node as visited and enqueue it
        visited[s] = true;
        q.add(s);

        // Iterate over the queue
        while (!q.isEmpty()) {

            // Dequeue a vertex and store it
            int curr = q.poll();
            res.add(curr);

            // Get all adjacent vertices of the dequeued 
            // vertex curr If an adjacent has not been 
            // visited, mark it visited and enqueue it
            for (int x : adj.get(curr)) {
                if (!visited[x]) {
                    visited[x] = true;
                    q.add(x);
                }
            }
        }
        return res;
    }

    // Perform BFS for the entire graph which maybe
    // disconnected
    static ArrayList<Integer> bfsDisconnected(
                ArrayList<ArrayList<Integer>> adj) {
        int V = adj.size();

        // create an array to store the traversal
        ArrayList<Integer> res = new ArrayList<>();

        // Initially mark all the vertices as not visited
        boolean[] visited = new boolean[V];

        // perform BFS for each node
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                bfsOfGraph(adj, i, visited, res);
            }
        }
        return res;
    }

    public static void main(String[] args) {
        ArrayList<ArrayList<Integer>> adj = new ArrayList<>();
        adj.add(new ArrayList<>(Arrays.asList(1, 2)));
        adj.add(new ArrayList<>(Arrays.asList(0))); 
        adj.add(new ArrayList<>(Arrays.asList(0)));   
        adj.add(new ArrayList<>(Arrays.asList(4)));
        adj.add(new ArrayList<>(Arrays.asList(3, 5)));
        adj.add(new ArrayList<>(Arrays.asList(4)));  

        int src = 0;
        ArrayList<Integer> ans = bfsDisconnected(adj);
        for (int i : ans) {
            System.out.print(i + " ");
        }
    }
}

// Output
// 0 1 2 3 4 5 


// Time Complexity: O(V + E), BFS explores all the vertices and edges in the graph. In the worst case, it visits every vertex and edge once. Therefore, the time complexity of BFS is O(V + E), where V and E are the number of vertices and edges in the given graph. 

// Auxiliary Space: O(V), BFS uses a queue to keep track of the vertices that need to be visited. In the worst case, the queue can contain all the vertices in the graph. Therefore, the space complexity of BFS is O(V).
