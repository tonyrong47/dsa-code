def range_sum_prefix(nums, queries):
    # Step 1: Precompute the prefix sum array
    n = len(nums)
    prefix = [0] * n
    prefix[0] = nums[0]
    for i in range(1, n):
        prefix[i] = prefix[i - 1] + nums[i]

    # Step 2: Answer each query in O(1)
    results = []
    for l, r in queries:
        if l == 0:
            results.append(prefix[r])        # sum from start to r
        else:
            results.append(prefix[r] - prefix[l - 1])  # subtract prefix before l
    return results


# Example usage
nums = [1, 2, 3, 4, 5]   # array
queries = [(0, 2), (1, 3), (2, 4)]

print(range_sum_prefix(nums, queries))
