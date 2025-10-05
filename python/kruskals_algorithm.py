class DSU:
    def __init__(self, nodes):
        self.parent = {n: n for n in nodes}
        self.rank = {n: 0 for n in nodes}

    def find(self, i):
        if self.parent[i] == i:
            return i
        self.parent[i] = self.find(self.parent[i])
        return self.parent[i]

    def union(self, i, j):
        root_i = self.find(i)
        root_j = self.find(j)

        if root_i != root_j:
            if self.rank[root_i] < self.rank[root_j]:
                self.parent[root_i] = root_j
            elif self.rank[root_i] > self.rank[root_j]:
                self.parent[root_j] = root_i
            else:
                self.parent[root_j] = root_i
                self.rank[root_i] += 1
            return True
        return False

def kruskals_mst(nodes, edges):
    
    # Edges are (weight, u, v)
    edges.sort()
    
    dsu = DSU(nodes)
    mst = []
    
    for w, u, v in edges:
        if dsu.union(u, v):
            mst.append((u, v, w))

    return mst

# Example
# nodes: a list of all vertices
N = ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I']
# edges: a list of (weight, u, v)
E = [
    (4, 'A', 'B'), (8, 'A', 'H'),
    (8, 'B', 'C'), (11, 'B', 'H'),
    (7, 'C', 'D'), (4, 'C', 'F'),
    (9, 'D', 'E'), (14, 'D', 'F'),
    (10, 'E', 'F'),
    (2, 'F', 'G'),
    (1, 'G', 'H'), (6, 'G', 'I'),
    (7, 'H', 'I')
]

mst_kruskal = kruskals_mst(N, E)
print(f"\nKruskal's MST Edges: {mst_kruskal}")