from collections import deque

def topological_sort(graph):
    # Calculate in-degrees for all nodes
    in_degree = {u: 0 for u in graph}
    for u in graph:
        for v in graph[u]:
            in_degree[v] += 1

    # Initialize queue with all nodes having an in-degree of 0
    queue = deque([u for u in graph if in_degree[u] == 0])
    
    result = []
    
    while queue:
        u = queue.popleft()
        result.append(u)

        # "Remove" u and update neighbors' in-degrees
        for v in graph[u]:
            in_degree[v] -= 1
            if in_degree[v] == 0:
                queue.append(v)

    # Check for cycle (if result length != number of nodes)
    if len(result) == len(graph):
        return result
    else:
        return "Graph has a cycle"

# Example: (0 -> 1, 0 -> 2, 1 -> 3, 2 -> 3)
G = {
    0: [1, 2],
    1: [3],
    2: [3],
    3: []
}

order = topological_sort(G)
print(f"Topological Order: {order}")

# Example with cycle: (A -> B, B -> A)
G_cycle = {
    'A': ['B'],
    'B': ['A'],
    'C': []
}
print(f"Topological Order (Cycle Check): {topological_sort(G_cycle)}")