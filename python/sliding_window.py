def sliding_window_sum(arr, k):
    n = len(arr)
    if k > n:
        return []

    # Compute sum of first window
    window_sum = sum(arr[:k])
    result = [window_sum]

    # Slide the window
    for i in range(k, n):
        window_sum += arr[i] - arr[i - k]
        result.append(window_sum)

    return result


# Example usage
arr = [1, 2, 3, 4, 5, 6]
k = 3
print(sliding_window_sum(arr, k))  # Output: [6, 9, 12, 15]
