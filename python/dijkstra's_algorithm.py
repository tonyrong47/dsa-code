import heapq

def dijkstra(graph, start):
    # dist: {node: shortest_distance}
    dist = {node: float('inf') for node in graph}
    dist[start] = 0
    # pq: stores tuples of (distance, node)
    pq = [(0, start)] 

    while pq:
        d, u = heapq.heappop(pq)

        # Skip if we found a shorter path already
        if d > dist[u]:
            continue

        for v, weight in graph[u].items():
            new_dist = dist[u] + weight
            
            if new_dist < dist[v]:
                dist[v] = new_dist
                heapq.heappush(pq, (new_dist, v))

    return dist

# Example
# Graph format: {node: {neighbor: weight, ...}, ...}
G = {
    'A': {'B': 1, 'C': 4},
    'B': {'C': 2, 'D': 5},
    'C': {'D': 1},
    'D': {'E': 3},
    'E': {}
}

shortest_paths = dijkstra(G, 'A')
print(f"Dijkstra's Shortest Paths from A: {shortest_paths}")