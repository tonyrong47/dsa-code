def linear_search(arr, target):

    for index, value in enumerate(arr):  
        if value == target:
            return index  
    return -1  

# Example
numbers = [10, 20, 30, 40, 50]
target = 30

    for i in range(len(arr)):
        if arr[i] == target:
            return i
    return -1

# Example usage
arr = [4, 2, 7, 1, 9]
target = 7
result = linear_search(arr, target)
print(f"Element found at index: {result}" if result != -1 else "Element not found")

