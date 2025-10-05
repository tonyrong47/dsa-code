def range_sum_brute_force(nums, queries):
    results = []
    for l, r in queries:     # loop over each query
        current_sum = 0
        for i in range(l, r + 1):  # inner loop over the range
            current_sum += nums[i]
        results.append(current_sum)
    return results


# Example usage
nums = [1, 2, 3, 4, 5]   # array
queries = [(0, 2), (1, 3), (2, 4)]  # (l, r) ranges

print(range_sum_brute_force(nums, queries))
