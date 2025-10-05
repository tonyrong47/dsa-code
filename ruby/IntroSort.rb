# frozen_string_literal: true

# Main entry point for the Introsort algorithm.
# It calculates the depth limit and calls the recursive sorter.
#
# @param arr [Array<Integer>] The array to be sorted.
def introsort(arr)
  return if arr.empty?

  depth_limit = (2 * Math.log2(arr.size)).floor
  introsort_recursive(arr, 0, arr.size - 1, depth_limit)
end

# The core recursive function for Introsort.
# It switches to Heap Sort if recursion depth is exceeded,
# and to Insertion Sort for small partitions.
#
# @param arr [Array<Integer>] The array to sort.
# @param begin_idx [Integer] The starting index of the partition.
# @param end_idx [Integer] The ending index of the partition.
# @param depth_limit [Integer] The maximum recursion depth.
def introsort_recursive(arr, begin_idx, end_idx, depth_limit)
  return if begin_idx >= end_idx

  size = end_idx - begin_idx + 1

  if size <= 16
    insertion_sort(arr, begin_idx, end_idx)
    return
  end

  if depth_limit.zero?
    heap_sort(arr, begin_idx, end_idx)
    return
  end

  pivot_index = partition(arr, begin_idx, end_idx)
  introsort_recursive(arr, begin_idx, pivot_index - 1, depth_limit - 1)
  introsort_recursive(arr, pivot_index + 1, end_idx, depth_limit - 1)
end

# Partitions the array for Quick Sort using the Lomuto partition scheme.
# It uses the last element as the pivot.
#
# @param arr [Array<Integer>] The array to partition.
# @param low [Integer] The starting index.
# @param high [Integer] The ending index.
# @return [Integer] The index of the pivot after partitioning.
def partition(arr, low, high)
  pivot = arr[high]
  i = low - 1
  (low...high).each do |j|
    if arr[j] <= pivot
      i += 1
      arr[i], arr[j] = arr[j], arr[i] # Swap
    end
  end
  arr[i + 1], arr[high] = arr[high], arr[i + 1] # Swap pivot into place
  i + 1
end

# Sorts a small partition of the array using Insertion Sort.
#
# @param arr [Array<Integer>] The array containing the partition.
# @param left [Integer] The starting index of the partition.
# @param right [Integer] The ending index of the partition.
def insertion_sort(arr, left, right)
  (left + 1..right).each do |i|
    key = arr[i]
    j = i - 1
    while j >= left && arr[j] > key
      arr[j + 1] = arr[j]
      j -= 1
    end
    arr[j + 1] = key
  end
end

# Sorts a partition of the array using Heap Sort.
#
# @param arr [Array<Integer>] The array containing the partition.
# @param begin_idx [Integer] The starting index of the partition.
# @param end_idx [Integer] The ending index of the partition.
def heap_sort(arr, begin_idx, end_idx)
  n = end_idx - begin_idx + 1
  offset = begin_idx

  # Build a maxheap.
  (n / 2 - 1).downto(0) do |i|
    heapify(arr, n, i, offset)
  end

  # One by one extract elements
  (n - 1).downto(0) do |i|
    arr[offset], arr[offset + i] = arr[offset + i], arr[offset] # Swap
    heapify(arr, i, 0, offset)
  end
end

# Helper function to heapify a subtree rooted with node i.
#
# @param arr [Array<Integer>] The array.
# @param n [Integer] The size of the heap.
# @param i [Integer] The root of the subtree.
# @param offset [Integer] The offset for the start of the array partition.
def heapify(arr, n, i, offset)
  largest = i
  left = 2 * i + 1
  right = 2 * i + 2

  largest = left if left < n && arr[offset + left] > arr[offset + largest]
  largest = right if right < n && arr[offset + right] > arr[offset + largest]

  return unless largest != i

  arr[offset + i], arr[offset + largest] = arr[offset + largest], arr[offset + i] # Swap
  heapify(arr, n, largest, offset)
end

# --- Driver Code ---
def main
  puts '--- Interactive Introsort in Ruby ---'
  print 'Enter the elements of the array (space-separated): '
  input = gets.chomp

  if input.strip.empty?
    puts 'No input provided. Exiting.'
    return
  end
  
  begin
    arr = input.split.map(&:to_i)
  rescue ArgumentError
    puts 'Invalid input. Please enter numbers only. Exiting.'
    return
  end


  puts "\nOriginal array: #{arr.inspect}"
  introsort(arr)
  puts "Sorted array:   #{arr.inspect}"
end

main if __FILE__ == $PROGRAM_NAME