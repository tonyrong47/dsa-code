def bfs(graph, start)
  visited = {}
  queue = [start]
  visited[start] = true

  while !queue.empty?
    node = queue.shift
    puts node  # Process the node (e.g., print or collect)

    graph[node]&.each do |neighbor|
      unless visited[neighbor]
        visited[neighbor] = true
        queue << neighbor
      end
    end
  end
end

# Example usage:
graph = {
  'A' => ['B', 'C'],
  'B' => ['D', 'E'],
  'C' => ['F'],
  'D' => [],
  'E' => ['F'],
  'F' => []
}

bfs(graph, 'A')