def floyd_warshall(n, graph)
  dist = Array.new(n) { Array.new(n, Float::INFINITY) }

  # Initialize distances from input graph
  n.times do |i|
    dist[i][i] = 0
  end

  graph.each do |u, v, w|
    dist[u][v] = w
  end

  # Floyd-Warshall core logic
  n.times do |k|
    n.times do |i|
      n.times do |j|
        if dist[i][k] + dist[k][j] < dist[i][j]
          dist[i][j] = dist[i][k] + dist[k][j]
        end
      end
    end
  end

  dist
end

# Example usage:
# Graph edges: [from, to, weight]
edges = [
  [0, 1, 3],
  [0, 2, 8],
  [1, 2, 2],
  [2, 3, 1],
  [3, 0, 4]
]

n = 4  # Number of nodes
result = floyd_warshall(n, edges)

# Output shortest distances
result.each_with_index do |row, i|
  puts "From node #{i}: #{row.map { |d| d == Float::INFINITY ? 'INF' : d }.join(' ')}"
end