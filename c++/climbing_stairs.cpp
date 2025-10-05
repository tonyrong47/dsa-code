//leetcode climbing stairs problem(leetcode 70) using dynamic programming 
//approach - Recursive memoization

#include <bits/stdc++.h>
using namespace std;

int solve(int n, vector<int> &dp)
{
    if (n == 0)
        return 1;
    if (n < 0)
        return 0;

    if (dp[n] != -1)
        return dp[n];

    return dp[n] = solve(n - 1, dp) + solve(n - 2, dp);
}
int climbStairs(int n)
{
    vector<int> dp(n + 1, -1);
    return solve(n, dp);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //n = total steps required to reach the top
    int n;
    cin >> n;

    cout<<"No of ways to reach the top are: "<<climbStairs(n);
    return 0;
}