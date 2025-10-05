from itertools import permutations
from typing import List

class Solution:
    def uniquePerms(self, arr: List[int]) -> List[List[int]]:
        # 1. itertools.permutations generates all possible permutations, including duplicates.
        all_perms_iterator = permutations(arr)

        # 2. Using a set removes duplicates (since arr may contain duplicate elements).
        unique_perms_set = set(all_perms_iterator)

        # 3. Convert to list of lists and sort them for predictable output.
        result = sorted([list(p) for p in unique_perms_set])

        return result


# ✅ Testing the function
if __name__ == "__main__":
    obj = Solution()

    # Example 1
    arr1 = [1, 1, 2]
    print("Input:", arr1)
    print("Unique permutations:")
    print(obj.uniquePerms(arr1))

    # Example 2
    arr2 = [1, 2, 3]
    print("\nInput:", arr2)
    print("Unique permutations:")
    print(obj.uniquePerms(arr2))
