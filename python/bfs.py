from collections import deque

def bfs(graph, start):
    visited = [False] * len(graph)
    queue = deque([start])
    visited[start] = True

    while queue:
        vertex = queue.popleft()
        print(vertex, end=" ")
        for neighbor in graph[vertex]:
            if not visited[neighbor]:
                visited[neighbor] = True
                queue.append(neighbor)

# Example usage
graph = [
    [1, 4],
    [0, 2, 3, 4],
    [1, 3],
    [1, 2, 4],
    [0, 1, 3]
]

print("BFS starting from vertex 0:")
bfs(graph, 0)
