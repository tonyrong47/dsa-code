class FenwickTree
  def initialize(size)
    @n = size
    @bit = Array.new(size + 1, 0)
  end

  # Add 'val' to index 'i' (0-based)
  def update(i, val)
    i += 1
    while i <= @n
      @bit[i] += val
      i += i & -i
    end
  end

  # Get prefix sum from 0 to i (0-based)
  def query(i)
    i += 1
    sum = 0
    while i > 0
      sum += @bit[i]
      i -= i & -i
    end
    sum
  end

  # Get sum in range [l, r] (0-based)
  def range_sum(l, r)
    query(r) - query(l - 1)
  end
end

# Example usage:
ft = FenwickTree.new(10)
ft.update(3, 5)     # Add 5 at index 3
ft.update(5, 2)     # Add 2 at index 5
puts ft.query(5)    # Sum from index 0 to 5 → Output: 7
puts ft.range_sum(3, 5)  # Sum from index 3 to 5 → Output: 7