def has_pair_with_sum(arr, target):
    # Ensure the array is sorted for two-pointer technique
    arr.sort()

    i, j = 0, len(arr) - 1  # Initialize two pointers

    while i < j:
        current_sum = arr[i] + arr[j]

        if current_sum == target:
            return True
        elif current_sum < target:
            i += 1  # Move the left pointer forward
        else:
            j -= 1  # Move the right pointer backward

    return False  # No pair found


# Example usage
arr = [10, 2, 5, 7, 3]
target = 12

print(has_pair_with_sum(arr, target))  # ✅ True (because 5 + 7 = 12)
