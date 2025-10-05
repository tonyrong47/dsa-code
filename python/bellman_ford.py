def bellman_ford_path(edges, start):
    nodes = set()
    for u, v, w in edges:
        nodes.add(u)
        nodes.add(v)

    dist = {n: float('inf') for n in nodes}
    dist[start] = 0
    V = len(nodes)

    for _ in range(V - 1):
        for u, v, w in edges:
            if dist[u] != float('inf') and dist[u] + w < dist[v]:
                dist[v] = dist[u] + w

    for u, v, w in edges:
        if dist[u] != float('inf') and dist[u] + w < dist[v]:
            return "Negative Cycle Detected"

    return dist

# Example
E = [
    ('A', 'B', -1),
    ('A', 'C', 4),
    ('B', 'C', 3),
    ('B', 'D', 2),
    ('B', 'E', 2),
    ('D', 'B', 1),
    ('E', 'D', -3)
]

start_node = 'A'
res = bellman_ford_path(E, start_node)
print(f"Shortest Paths from {start_node}: {res}")