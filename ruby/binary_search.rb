def binary_search(arr, target)
  left = 0
  right = arr.length - 1

  while left <= right
    mid = (left + right) / 2
    if arr[mid] == target
      return mid
    elsif arr[mid] < target
      left = mid + 1
    else
      right = mid - 1
    end
  end

  -1
end

def binary_search_recursive(arr, target, left = 0, right = arr.length - 1)
  return -1 if left > right

  mid = (left + right) / 2
  if arr[mid] == target
    mid
  elsif arr[mid] < target
    binary_search_recursive(arr, target, mid + 1, right)
  else
    binary_search_recursive(arr, target, left, mid - 1)
  end
end

arr = [1, 3, 5, 7, 9, 11]

puts "Iterative Search:"
puts "Index of 7: #{binary_search(arr, 7)}"
puts "Index of 100: #{binary_search(arr, 100)}"

puts "\nRecursive Search:"
puts "Index of 9: #{binary_search_recursive(arr, 9)}"
puts "Index of 2: #{binary_search_recursive(arr, 2)}"
