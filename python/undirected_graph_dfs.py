def is_cycle_dfs(graph, node, visited, parent):
    visited.add(node)
    for neighbor in graph[node]:
        if neighbor not in visited:
            if is_cycle_dfs(graph, neighbor, visited, node):
                return True
        elif neighbor != parent:
            return True
    return False

def has_cycle(graph):
    visited = set()
    for node in graph:
        if node not in visited:
            if is_cycle_dfs(graph, node, visited, -1):
                return True
    return False

graph = {
    0: [1, 2],
    1: [0, 3],
    2: [0],
    3: [1, 4],
    4: [3]
}
print("\nGraph contains cycle?" , has_cycle(graph))
