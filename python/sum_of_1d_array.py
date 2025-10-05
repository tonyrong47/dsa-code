from typing import List

def running_sum(nums: List[int]) -> List[int]:
    """
    Calculates the running sum of a 1D array.

    The running sum of an array is defined as runningSum[i] = sum(nums[0]...nums[i]).

    Args:
        nums: A list of integers.

    Returns:
        A list of integers representing the running sum.
    """
    if not nums:
        return []

    result = []
    current_sum = 0
    for num in nums:
        current_sum += num
        result.append(current_sum)
    return result

if __name__ == "__main__":
    # Example usage
    nums1 = [1, 2, 3, 4]
    print(f"Original array: {nums1}")
    print(f"Running sum: {running_sum(nums1)}") # Expected: [1, 3, 6, 10]

    nums2 = [3, 1, 2, 10, 1]
    print(f"Original array: {nums2}")
    print(f"Running sum: {running_sum(nums2)}") # Expected: [3, 4, 6, 16, 17]

    nums3 = []
    print(f"Original array: {nums3}")
    print(f"Running sum: {running_sum(nums3)}") # Expected: []

    nums4 = [5]
    print(f"Original array: {nums4}")
    print(f"Running sum: {running_sum(nums4)}") # Expected: [5]
