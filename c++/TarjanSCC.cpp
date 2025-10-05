/**
 * @file TarjanSCC.cpp
 * @brief Implementation of Tarjan's Algorithm for Strongly Connected Components
 * @author Hacktoberfest Contributor
 * @date October 2025
 *
 * Problem: Find all Strongly Connected Components (SCCs) in a directed graph
 *
 * Strongly Connected Component: A maximal set of vertices where every vertex
 * is reachable from every other vertex in the set.
 *
 * Algorithm: Tarjan's Algorithm (Single DFS with Stack)
 * - Use DFS to traverse graph
 * - Track discovery time (when node first visited)
 * - Track low-link value (earliest discovered node reachable in subtree)
 * - Use stack to keep track of nodes in current SCC
 * - When low[u] == disc[u], we found an SCC root
 *
 * Key Insight: A node is the root of an SCC if it's the first node discovered
 * in that component. All nodes in the SCC will be on the stack above it.
 *
 * Time Complexity: O(V + E) - single DFS traversal
 * Space Complexity: O(V) - for recursion stack, discovery/low arrays, and stack
 *
 * Applications:
 * - Finding cycles in directed graphs
 * - Graph condensation (converting to DAG)
 * - 2-SAT problem solving
 * - Dead code elimination in compilers
 */

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <climits>
using namespace std;

class TarjanSCC {
private:
    int V;                           // Number of vertices
    vector<vector<int>> adj;         // Adjacency list
    vector<int> disc;                // Discovery time of vertices
    vector<int> low;                 // Earliest discovered vertex reachable
    vector<bool> onStack;            // Track if vertex is on stack
    stack<int> st;                   // Stack to store vertices
    vector<vector<int>> sccs;        // Store all SCCs
    int timer;                       // Counter for discovery time

    /**
     * @brief DFS utility function for Tarjan's algorithm
     * @param u Current vertex
     *
     * Algorithm Logic:
     * 1. Set disc[u] = low[u] = timer++
     * 2. Push u onto stack and mark onStack[u] = true
     * 3. For each neighbor v:
     *    a. If v not visited: recursively call DFS, update low[u]
     *    b. If v on stack: update low[u] = min(low[u], disc[v])
     * 4. If low[u] == disc[u]: u is root of SCC
     *    - Pop stack until u is found
     *    - All popped vertices form one SCC
     */
    void DFS(int u) {
        // Initialize discovery time and low value
        disc[u] = low[u] = timer++;
        st.push(u);
        onStack[u] = true;

        // Explore all neighbors
        for (int v : adj[u]) {
            if (disc[v] == -1) {
                // v is not visited - recurse
                DFS(v);

                // Update low[u] based on subtree
                low[u] = min(low[u], low[v]);

            } else if (onStack[v]) {
                // v is on stack (part of current SCC path)
                // Update low[u] to earlier discovered node
                low[u] = min(low[u], disc[v]);
            }
        }

        // If u is root of SCC (low[u] == disc[u])
        if (low[u] == disc[u]) {
            vector<int> component;

            // Pop all vertices of this SCC from stack
            while (true) {
                int v = st.top();
                st.pop();
                onStack[v] = false;
                component.push_back(v);

                if (v == u) break;  // Found root
            }

            // Sort for consistent output
            sort(component.begin(), component.end());
            sccs.push_back(component);
        }
    }

public:
    /**
     * @brief Constructor - initialize graph
     * @param vertices Number of vertices
     */
    TarjanSCC(int vertices) : V(vertices) {
        adj.resize(V);
        disc.assign(V, -1);
        low.assign(V, -1);
        onStack.assign(V, false);
        timer = 0;
    }

    /**
     * @brief Add directed edge to graph
     * @param u Source vertex
     * @param v Destination vertex
     */
    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    /**
     * @brief Find all SCCs using Tarjan's algorithm
     * @return Vector of SCCs (each SCC is a vector of vertices)
     */
    vector<vector<int>> findSCCs() {
        sccs.clear();

        // Call DFS for all unvisited vertices
        for (int i = 0; i < V; i++) {
            if (disc[i] == -1) {
                DFS(i);
            }
        }

        // Sort SCCs by size (largest first) for better visualization
        sort(sccs.begin(), sccs.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a.size() > b.size();
             });

        return sccs;
    }

    /**
     * @brief Print all SCCs
     */
    void printSCCs() {
        vector<vector<int>> components = findSCCs();

        cout << "\nTotal Strongly Connected Components: " << components.size() << endl;
        cout << "\nComponents:" << endl;

        for (int i = 0; i < components.size(); i++) {
            cout << "SCC " << (i + 1) << " (size " << components[i].size() << "): ";
            for (int vertex : components[i]) {
                cout << vertex << " ";
            }
            cout << endl;
        }
    }

    /**
     * @brief Check if graph is strongly connected
     * @return true if entire graph is one SCC
     */
    bool isStronglyConnected() {
        vector<vector<int>> components = findSCCs();
        return components.size() == 1;
    }

    /**
     * @brief Build condensed DAG from SCCs
     * @return Adjacency list of condensed graph
     *
     * Condensed graph: Each SCC becomes a single node
     * Useful for finding dependencies between components
     */
    vector<vector<int>> buildCondensedGraph() {
        vector<vector<int>> components = findSCCs();
        int numSCCs = components.size();

        // Map each vertex to its SCC index
        vector<int> vertexToSCC(V);
        for (int i = 0; i < numSCCs; i++) {
            for (int v : components[i]) {
                vertexToSCC[v] = i;
            }
        }

        // Build condensed graph
        vector<vector<int>> condensed(numSCCs);
        vector<vector<bool>> hasEdge(numSCCs, vector<bool>(numSCCs, false));

        for (int u = 0; u < V; u++) {
            for (int v : adj[u]) {
                int sccU = vertexToSCC[u];
                int sccV = vertexToSCC[v];

                // Add edge between different SCCs (avoid duplicates)
                if (sccU != sccV && !hasEdge[sccU][sccV]) {
                    condensed[sccU].push_back(sccV);
                    hasEdge[sccU][sccV] = true;
                }
            }
        }

        return condensed;
    }

    /**
     * @brief Print graph structure
     */
    void printGraph() {
        cout << "\nGraph Adjacency List:" << endl;
        for (int i = 0; i < V; i++) {
            cout << i << " -> ";
            for (int v : adj[i]) {
                cout << v << " ";
            }
            cout << endl;
        }
    }
};

/**
 * @brief Example usage and test cases
 */
int main() {
    // Test Case 1: Classic SCC example
    cout << "=== Test Case 1: Classic SCC Example ===" << endl;
    TarjanSCC g1(5);
    g1.addEdge(0, 1);
    g1.addEdge(1, 2);
    g1.addEdge(2, 0);  // Cycle: 0-1-2-0
    g1.addEdge(1, 3);
    g1.addEdge(3, 4);

    g1.printGraph();
    g1.printSCCs();

    // Expected: {0,1,2}, {3}, {4}

    // Test Case 2: Multiple cycles
    cout << "\n=== Test Case 2: Multiple Independent Cycles ===" << endl;
    TarjanSCC g2(8);
    // First cycle: 0-1-2-0
    g2.addEdge(0, 1);
    g2.addEdge(1, 2);
    g2.addEdge(2, 0);

    // Second cycle: 3-4-5-3
    g2.addEdge(3, 4);
    g2.addEdge(4, 5);
    g2.addEdge(5, 3);

    // Connection between cycles
    g2.addEdge(2, 3);

    // Isolated vertices
    g2.addEdge(6, 7);

    g2.printSCCs();

    // Test Case 3: Single strongly connected graph
    cout << "\n=== Test Case 3: Fully Connected Graph ===" << endl;
    TarjanSCC g3(4);
    g3.addEdge(0, 1);
    g3.addEdge(1, 2);
    g3.addEdge(2, 3);
    g3.addEdge(3, 0);
    g3.addEdge(0, 2);
    g3.addEdge(2, 1);

    g3.printSCCs();
    cout << "Is strongly connected: "
         << (g3.isStronglyConnected() ? "Yes" : "No") << endl;

    // Test Case 4: Complex graph with nested cycles
    cout << "\n=== Test Case 4: Complex Graph ===" << endl;
    TarjanSCC g4(7);
    g4.addEdge(0, 1);
    g4.addEdge(1, 2);
    g4.addEdge(2, 0);  // SCC: {0,1,2}
    g4.addEdge(2, 3);
    g4.addEdge(3, 4);
    g4.addEdge(4, 5);
    g4.addEdge(5, 3);  // SCC: {3,4,5}
    g4.addEdge(4, 6);

    g4.printGraph();
    g4.printSCCs();

    // Test Case 5: Condensed graph (DAG of SCCs)
    cout << "\n=== Test Case 5: Condensed Graph ===" << endl;
    TarjanSCC g5(6);
    g5.addEdge(0, 1);
    g5.addEdge(1, 0);  // SCC1: {0,1}
    g5.addEdge(1, 2);
    g5.addEdge(2, 3);
    g5.addEdge(3, 2);  // SCC2: {2,3}
    g5.addEdge(3, 4);
    g5.addEdge(4, 5);
    g5.addEdge(5, 4);  // SCC3: {4,5}

    vector<vector<int>> sccs = g5.findSCCs();
    vector<vector<int>> condensed = g5.buildCondensedGraph();

    cout << "Original SCCs:" << endl;
    for (int i = 0; i < sccs.size(); i++) {
        cout << "SCC " << i << ": ";
        for (int v : sccs[i]) {
            cout << v << " ";
        }
        cout << endl;
    }

    cout << "\nCondensed Graph (SCC dependencies):" << endl;
    for (int i = 0; i < condensed.size(); i++) {
        cout << "SCC " << i << " -> ";
        for (int j : condensed[i]) {
            cout << "SCC " << j << " ";
        }
        cout << endl;
    }

    return 0;
}
