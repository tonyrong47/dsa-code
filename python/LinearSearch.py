def linear_search(arr, target):
    """
    Performs linear search on a list to find the target value.
    
    Args:
        arr (list): The list to search in.
        target (any): The value to search for.
        
    Returns:
        int: The index of the target if found, else -1.
    """
    for index, value in enumerate(arr):
        if value == target:
            return index  # Target found
    return -1  # Target not found

# Example usage
numbers = [10, 20, 30, 40, 50]
target = 30

result = linear_search(numbers, target)

if result != -1:
    print(f"Element {target} found at index {result}.")
else:
    print(f"Element {target} not found in the list.")
