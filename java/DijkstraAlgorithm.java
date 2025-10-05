import java.util.*;

public class DijkstraAlgorithm {

    // A utility class to represent a node in the priority queue
    static class Node implements Comparable<Node> {
        int vertex;
        int distance;

        Node(int vertex, int distance) {
            this.vertex = vertex;
            this.distance = distance;
        }

        @Override
        public int compareTo(Node other) {
            return Integer.compare(this.distance, other.distance);
        }
    }

    // Function to implement Dijkstra's algorithm
    public static void dijkstra(int[][] graph, int source) {
        int n = graph.length;
        int[] dist = new int[n];
        boolean[] visited = new boolean[n];
        PriorityQueue<Node> pq = new PriorityQueue<>();

        // Initialize distances
        Arrays.fill(dist, Integer.MAX_VALUE);
        dist[source] = 0;
        pq.add(new Node(source, 0));

        while (!pq.isEmpty()) {
            Node current = pq.poll();
            int u = current.vertex;

            if (visited[u]) continue;
            visited[u] = true;

            // Update distances of adjacent vertices
            for (int v = 0; v < n; v++) {
                if (graph[u][v] != 0 && !visited[v]) {
                    int newDist = dist[u] + graph[u][v];
                    if (newDist < dist[v]) {
                        dist[v] = newDist;
                        pq.add(new Node(v, newDist));
                    }
                }
            }
        }

        // Print the shortest distances
        System.out.println("Shortest distances from vertex " + source + ":");
        for (int i = 0; i < n; i++) {
            System.out.println("Vertex " + i + " : " + (dist[i] == Integer.MAX_VALUE ? "Infinity" : dist[i]));
        }
    }

    public static void main(String[] args) {
        // Sample graph represented as adjacency matrix
        // 0: A, 1: B, 2: C, 3: D, 4: E
        int[][] graph = {
            {0, 4, 0, 0, 0},  // A to B: 4
            {4, 0, 8, 0, 0},  // B to A: 4, B to C: 8
            {0, 8, 0, 7, 0},  // C to B: 8, C to D: 7
            {0, 0, 7, 0, 9},  // D to C: 7, D to E: 9
            {0, 0, 0, 9, 0}   // E to D: 9
        };

        int source = 0;  // Starting from vertex A (0)
        dijkstra(graph, source);
    }
}
