class Solution:
    def minParentheses(self, s: str) -> int:
        stack = []
        ans = 0
        for e in s:
            if e == "(":
                stack.append(e)
            else:  # e == ")"
                if stack:
                    stack.pop()
                else:
                    ans += 1
        ans += len(stack)
        return ans


# ✅ Testing
if __name__ == "__main__":
    obj = Solution()

    # Example test cases
    test_cases = [
        "())",       # needs 1 "("
        "(((",       # needs 3 ")"
        ")))",       # needs 3 "("
        "()()",      # already balanced
        "(()))(",    # needs 2
    ]

    for s in test_cases:
        print(f"Input: {s}  ->  Min insertions needed: {obj.minParentheses(s)}")
