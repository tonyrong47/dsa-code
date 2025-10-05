class Solution:
    def fourSum(self, nums, target):
        """
        Finds all unique quadruplets in the list that sum up to the target.

        :param nums: List[int] - input list of integers
        :param target: int - the target sum
        :return: List[List[int]] - list of unique quadruplets
        """
        nums.sort()  # Sort the array for two-pointer approach and duplicate handling
        n = len(nums)
        results = []

        # Loop for the first number
        for i in range(n - 3):
            # Skip duplicates for the first number
            if i > 0 and nums[i] == nums[i - 1]:
                continue

            # Early termination if smallest possible sum is already greater than target
            if nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target:
                break
            # Skip if the largest possible sum starting from nums[i] is still less than target
            if nums[i] + nums[n - 3] + nums[n - 2] + nums[n - 1] < target:
                continue

            # Loop for the second number
            for j in range(i + 1, n - 2):
                # Skip duplicates for the second number
                if j > i + 1 and nums[j] == nums[j - 1]:
                    continue

                # Early termination for second number
                if nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target:
                    break
                if nums[i] + nums[j] + nums[n - 2] + nums[n - 1] < target:
                    continue

                # Two pointers for the remaining two numbers
                left, right = j + 1, n - 1
                while left < right:
                    total = nums[i] + nums[j] + nums[left] + nums[right]
                    if total == target:
                        results.append([nums[i], nums[j], nums[left], nums[right]])
                        left += 1
                        right -= 1
                        # Skip duplicates
                        while left < right and nums[left] == nums[left - 1]:
                            left += 1
                        while left < right and nums[right] == nums[right + 1]:
                            right -= 1
                    elif total < target:
                        left += 1
                    else:
                        right -= 1

        return results
