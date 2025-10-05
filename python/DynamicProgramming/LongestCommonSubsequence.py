"""
Name: Longest Common Subsequence (LCS)

Problem: Find the length of the longest subsequence common to two strings.

Link: https://leetcode.com/problems/longest-common-subsequence/description/
"""

# Solution
def lcs(X, Y):
    m, n = len(X), len(Y)   
    dp = [[0] * (n + 1) for _ in range(m + 1)]
    for i in range(1, m + 1):
        for j in range(1, n + 1):
            if X[i - 1] == Y[j - 1]:
                dp[i][j] = dp[i - 1][j - 1] + 1
            else:
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])
    return dp[m][n]


# Input
if __name__ == "__main__":
    X = "ABCBDAB" 
    Y = "BDCAB"
    print("Length of LCS:", lcs(X, Y)) # Output: 4


# Explanation:
# - Function to compute the length of the Longest Common Subsequence (LCS) 
#   between two strings X and Y using Dynamic Programming. - line 10
# - Step 1: Get lengths of input strings - line 11
# - Step 2: Initialize a 2D DP table with zeros - line 12
# - Step 3: Build the DP table in a bottom-up manner - line 13-14
#    - Step 3a: If current characters match, add 1 to the result from previous indices - line 15-16
#    - Step 3b: If no match, take the max of ignoring one character from either string - line 17-18
# - Step 4: Return the value in the bottom-right cell, which is the length of LCS - line 19
# - Step 5: Example usage - line 23-25
# - Step 6: Call the lcs function and print the result - line 26


"""
Complexity Analysis:

Time Complexity: O(m * n)
    - m = len(X), n = len(Y)

Space Complexity: O(m * n)
    - 2D DP table of size (m+1) x (n+1) is used.
"""
