def is_cyclic_util(graph, v, visited, parent):
    visited[v] = True
    for neighbor in graph[v]:
        if not visited[neighbor]:
            if is_cyclic_util(graph, neighbor, visited, v):
                return True
        elif parent != neighbor:
            return True
    return False

def is_cyclic(graph):
    visited = [False] * len(graph)
    for i in range(len(graph)):
        if not visited[i]:
            if is_cyclic_util(graph, i, visited, -1):
                return True
    return False

# Example usage
graph = [
    [1, 2],
    [0, 2],
    [0, 1, 3],
    [2]
]

print("Graph has cycle:" , is_cyclic(graph))
