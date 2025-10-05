// house robber problem (leetcode 198) using dynamic programming
// approach - recursive memoization(top down)

#include <bits/stdc++.h>
using namespace std;
int solve(int i, vector<int> &nums, int n, vector<int> &dp)
{
    if (i >= n)
        return 0;
    if (dp[i] != -1)
        return dp[i];

    int inc = nums[i] + solve(i + 2, nums, n, dp);
    int exc = solve(i + 1, nums, n, dp);
    return dp[i] = max(inc, exc);
}
int rob(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n + 1, -1);
    return solve(0, nums, n, dp);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // n= no of houses
    int n;
    cin >> n;

    // nums[i] represents amount of money we can rob from ith house
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    cout << "max amount of money you can rob without alerting the police is: " << rob(nums);

    return 0;
}