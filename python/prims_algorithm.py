import heapq

def prims_mst(graph):
    V = list(graph.keys())
    if not V:
        return []

    start = V[0]
    visited = {start}
    mst = []
    
    # Priority queue stores (weight, u, v)
    edges = [(w, start, v) for v, w in graph.get(start, [])]
    heapq.heapify(edges)

    while edges and len(mst) < len(V) - 1:
        w, u, v = heapq.heappop(edges)

        if v not in visited:
            visited.add(v)
            mst.append((u, v, w))

            for neighbor, weight in graph.get(v, []):
                if neighbor not in visited:
                    heapq.heappush(edges, (weight, v, neighbor))

    return mst

# Example
# Graph represented as an adjacency list: {node: [(neighbor, weight), ...]}
G = {
    'A': [('B', 4), ('H', 8)],
    'B': [('A', 4), ('C', 8), ('H', 11)],
    'C': [('B', 8), ('D', 7), ('F', 4)],
    'D': [('C', 7), ('E', 9), ('F', 14)],
    'E': [('D', 9), ('F', 10)],
    'F': [('C', 4), ('D', 14), ('E', 10), ('G', 2)],
    'G': [('F', 2), ('H', 1), ('I', 6)],
    'H': [('A', 8), ('B', 11), ('G', 1), ('I', 7)],
    'I': [('G', 6), ('H', 7)]
}

mst_edges = prims_mst(G)
print(f"Prim's MST Edges: {mst_edges}")