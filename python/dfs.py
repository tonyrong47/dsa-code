def dfs(graph, start, visited=None):
    if visited is None:
        visited = set()
    visited.add(start)
    print(start, end=" ")
    for neighbor in graph[start]:
        if neighbor not in visited:
            dfs(graph, neighbor, visited)

# Example usage
graph = [
    [1, 4],
    [0, 2, 3, 4],
    [1, 3],
    [1, 2, 4],
    [0, 1, 3]
]

print("DFS starting from vertex 0:")
dfs(graph, 0)
