import doctest
from typing import List, TypeVar

# A generic type for comparable elements
T = TypeVar('T')


def merge_sort(arr: List[T]) -> List[T]:
    """
    Sorts a list in ascending order using the Merge Sort algorithm.

    This function is not in-place; it returns a new sorted list, leaving
    the original list unmodified.

    Args:
        arr: A list of comparable elements.

    Returns:
        A new list containing the sorted elements.

    Examples:
    >>> merge_sort([38, 27, 43, 3, 9, 82, 10])
    [3, 9, 10, 27, 38, 43, 82]
    >>> merge_sort([])
    []
    >>> merge_sort([5])
    [5]
    >>> merge_sort([10, 9, 8, 7, 6])
    [6, 7, 8, 9, 10]
    """
    # Base case: A list with 0 or 1 element is already sorted
    if len(arr) <= 1:
        return arr

    # 1. Divide: Find the middle and split the list into two halves
    mid = len(arr) // 2
    left_half = arr[:mid]
    right_half = arr[mid:]

    # 2. Conquer: Recursively sort both halves
    sorted_left = merge_sort(left_half)
    sorted_right = merge_sort(right_half)

    # 3. Combine: Merge the two sorted halves
    merged_array = []
    left_pointer, right_pointer = 0, 0

    while left_pointer < len(sorted_left) and right_pointer < len(sorted_right):
        if sorted_left[left_pointer] < sorted_right[right_pointer]:
            merged_array.append(sorted_left[left_pointer])
            left_pointer += 1
        else:
            merged_array.append(sorted_right[right_pointer])
            right_pointer += 1

    # Append any remaining elements from the left or right half
    merged_array.extend(sorted_left[left_pointer:])
    merged_array.extend(sorted_right[right_pointer:])

    return merged_array


if __name__ == "__main__":
    # Run the embedded doctests to verify the function's correctness
    doctest.testmod()

    # --- Example Usage ---
    original_list = [38, 27, 43, 3, 9, 82, 10]
    print(f"Original list: {original_list}")

    sorted_list = merge_sort(original_list)
    print(f"New sorted list: {sorted_list}")
    print(f"Original list remains unchanged: {original_list}")