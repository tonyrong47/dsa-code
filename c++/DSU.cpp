// Features:

// findUPar(x) → Finds the parent (with path compression).

// unionByRank(u, v) → Merges sets based on rank.

// unionBySize(u, v) → Merges sets based on size.

// Both heuristics give nearly O(α(N)) complexity (almost constant).

#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
    vector<int> parent, rank, size;

public:
    // Constructor
    DisjointSet(int n)
    {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        size.resize(n + 1, 1);

        for (int i = 0; i <= n; i++)
        {
            parent[i] = i; // each node is its own parent
        }
    }

    // Find with path compression
    int findUPar(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]); // path compression
    }

    // Union by Rank
    void unionByRank(int u, int v)
    {
        int pu = findUPar(u);
        int pv = findUPar(v);

        if (pu == pv)
            return; // already in same set

        if (rank[pu] < rank[pv])
        {
            parent[pu] = pv;
        }
        else if (rank[pv] < rank[pu])
        {
            parent[pv] = pu;
        }
        else
        {
            parent[pv] = pu;
            rank[pu]++; // increase rank if equal
        }
    }

    // Union by Size
    void unionBySize(int u, int v)
    {
        int pu = findUPar(u);
        int pv = findUPar(v);

        if (pu == pv)
            return; // already in same set

        if (size[pu] < size[pv])
        {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else
        {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

int main()
{
    DisjointSet ds(7);

    ds.unionBySize(1, 2);
    ds.unionBySize(2, 3);
    ds.unionBySize(4, 5);
    ds.unionBySize(6, 7);
    ds.unionBySize(5, 6);

    // check if 3 and 7 belong to the same component
    if (ds.findUPar(3) == ds.findUPar(7))
        cout << "Same Component\n";
    else
        cout << "Different Components\n";

    ds.unionBySize(3, 7);

    if (ds.findUPar(3) == ds.findUPar(7))
        cout << "Same Component\n";
    else
        cout << "Different Components\n";

    return 0;
}
