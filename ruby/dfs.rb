def dfs(graph, node, visited = Set.new)
  return if visited.include?(node)
  visited.add(node)
  puts node

  graph[node]&.each do |neighbor|
    dfs(graph, neighbor, visited)
  end
end