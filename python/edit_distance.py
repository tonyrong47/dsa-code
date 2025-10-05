def edit_distance(str1, str2):
    m, n = len(str1), len(str2)
    dp = [[0] * (n + 1) for _ in range(m + 1)]

    for i in range(m + 1):
        for j in range(n + 1):
            if i == 0:
                dp[i][j] = j
            elif j == 0:
                dp[i][j] = i
            elif str1[i-1] == str2[j-1]:
                dp[i][j] = dp[i-1][j-1]
            else:
                dp[i][j] = 1 + min(dp[i-1][j],    # Remove
                                   dp[i][j-1],    # Insert
                                   dp[i-1][j-1])  # Replace

    return dp[m][n]

# Example usage
str1 = "sunday"
str2 = "saturday"
print(f"Edit distance between '{str1}' and '{str2}' is {edit_distance(str1, str2)}")
