def coin_change(coins, amount):
    dp = [0] * (amount + 1)
    dp[0] = 1

    for coin in coins:
        for x in range(coin, amount + 1):
            dp[x] += dp[x - coin]

    return dp[amount]

# Example usage
coins = [1, 2, 5]
amount = 5
print(f"Number of ways to make amount {amount}:", coin_change(coins, amount))
