import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
public class bfsTraversal {
    public static void main(String[] args) {
        // Example graph with 5 nodes (0 to 4)
        ArrayList<ArrayList<Integer>> adj = new ArrayList<>();
        int V = 5; // number of vertices
        for (int i = 0; i < V; i++) adj.add(new ArrayList<>());

        // Example edges (undirected graph)
        adj.get(0).add(1);
        adj.get(0).add(2);
        adj.get(1).add(3);
        adj.get(2).add(4);

        bfsTraversal obj = new bfsTraversal();
        ArrayList<Integer> result = obj.bfs(adj, V);
        System.out.println(result); // Output should be BFS order
    }

    public ArrayList<Integer> bfs(ArrayList<ArrayList<Integer>> adj, int V) {
        ArrayList<Integer> ans = new ArrayList<>();
        boolean vis[] = new boolean[V];
        Queue<Integer> q = new LinkedList<>();

        // start BFS from node 0
        q.add(0);
        vis[0] = true;

        while (!q.isEmpty()) {
            int node = q.poll();
            ans.add(node);

            for (int nei : adj.get(node)) {
                if (!vis[nei]) {
                    vis[nei] = true;
                    q.add(nei);
                }
            }
        }
        return ans;
    }
}