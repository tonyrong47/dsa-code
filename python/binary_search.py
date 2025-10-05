def binary_search(arr, target):
    left, right = 0, len(arr) - 1
    while left <= right:
        mid = (left + right) // 2
        if arr[mid] == target:
            return mid
        elif arr[mid] < target:
            left = mid + 1
        else:
            right = mid - 1
    return -1

# Example usage
arr = [1, 2, 4, 7, 9]
target = 7
result = binary_search(arr, target)
print(f"Element found at index: {result}" if result != -1 else "Element not found")
