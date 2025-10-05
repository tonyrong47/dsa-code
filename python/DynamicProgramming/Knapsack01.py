"""
Name: 0/1 Knapsack Problem

Problem: Given weights and values of n items, put these items in a knapsack of capacity W 
to get the maximum total value in the knapsack. You cannot break items; each item is either 
taken or not taken (0/1 property).

Link: 'https://leetcode.com/discuss/post/1152328/01-knapsack-problem-and-dynamic-programm-4had/'

Try: 'https://leetcode.com/problems/ones-and-zeroes/solutions/95808/0-1-knapsack-in-python/'
"""

# Solution
def knapsack(values, weights, W):
    n = len(values) 
    dp = [[0] * (W + 1) for _ in range(n + 1)] 
    for i in range(1, n + 1):  
        for w in range(1, W + 1):  
            if weights[i - 1] <= w: 
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]) 
            else:
                dp[i][w] = dp[i - 1][w] 
    return dp[n][W]  

# Input
if __name__ == "__main__":  
    values = [60, 100, 120]  
    weights = [10, 20, 30]  
    W = 50  
    print("Maximum value in Knapsack:", knapsack(values, weights, W)) # Output: 220

# Explanation:
# - Function to compute the maximum value that can be put in a knapsack of capacity W 
#   using Dynamic Programming - line 14
# - Step 1: Get number of items - line 15
# - Step 2: Initialize a 2D DP table with zeros - line 16
# - Step 3: Build the DP table in a bottom-up manner - line 19-22
#    - Step 3a: If current item can be included, take the max of including or skipping it - line 19-20
#    - Step 3b: If item cannot be included, copy the value from above - line 21-22
# - Step 4: Return the value in the bottom-right cell, which is the maximum value - line 23
# - Step 5: Example usage - line 26-29
# - Step 6: Call the knapsack function and print the result - line 30


"""
Complexity Analysis:

Time Complexity: O(n * W)
    - n = number of items, W = capacity of knapsack

Space Complexity: O(n * W)
    - 2D DP table of size (n+1) x (W+1) is used
"""
