"""
Name: Coin Change Problem (Optimal Space & Time)

Problem: Given an integer array coins representing coins of different denominations 
and an integer amount, return the fewest number of coins needed to make up that amount. 
If that amount cannot be made up by any combination of the coins, return -1.

Optimal Approach: Uses a single 1D DP array for space efficiency and bottom-up calculation.

Link: https://leetcode.com/problems/coin-change/
"""

# Solution
def coinChange(coins, amount):
    dp = [amount + 1] * (amount + 1)  # line 12
    dp[0] = 0 
    for i in range(1, amount + 1):  
        for coin in coins:  
            if coin <= i: 
                dp[i] = min(dp[i], dp[i - coin] + 1)  
    return dp[amount] if dp[amount] <= amount else -1  

#Input
if __name__ == "__main__": 
    coins = [1, 2, 5] 
    amount = 11 
    print("Minimum coins needed:", coinChange(coins, amount)) # Output: 3 (5 + 5 + 1)


# Explanation:
# - Function to compute the minimum number of coins needed to make up a given amount using optimal 1D DP - line 14
# - Step 1: Initialize a DP array of size amount+1 with amount+1 as placeholder, dp[0] = 0 - line 15-16
# - Step 2: Fill the DP array bottom-up - line 17-18
#    - Step 2a: For each coin, update dp[i] as the minimum between current and dp[i - coin] + 1 - line 19-20
# - Step 3: Return dp[amount] if it is ≤ amount, else return -1 - line 21
# - Step 4: Example usage - line 24-27
# - Step 5: Call the coinChange function and print the result - line 27

"""
Complexity Analysis:

Time Complexity: O(n * amount)
    - n = number of coins, amount = target amount
    - Each amount is processed for every coin

Space Complexity: O(amount)
    - Only a 1D DP array of size amount + 1 is used
"""
