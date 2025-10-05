// There is a pizza with 3n slices of varying size, you and your friends will take slices of pizza as follows:

// You will pick any pizza slice.
// Your friend Alice will pick the next slice in the anti-clockwise direction of your pick.
// Your friend Bob will pick the next slice in the clockwise direction of your pick.
// Repeat until there are no more slices of pizzas.
// Given an integer array slices that represent the sizes of the pizza slices in a clockwise direction, return the maximum possible sum of slice sizes that you can pick.
// Input: slices = [1,2,3,4,5,6]
// Output: 10

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Solve the linear version: choose t items from arr[0..L-1] with no adjacent picks
    long long solveLinear(const vector<int>& arr, int t) {
        int L = arr.size();
        // dp[i][j] = best sum using first i elements (i from 0..L) picking exactly j items
        // initialize with very negative number for impossible states
        const long long NEG = LLONG_MIN / 4;
        vector<vector<long long>> dp(L + 1, vector<long long>(t + 1, NEG));

        dp[0][0] = 0; // using 0 items, picking 0 gives sum 0
        // iterate over number of taken elements from 1..L
        for (int i = 1; i <= L; ++i) {
            dp[i][0] = 0; // picking 0 items always sum to 0
            for (int j = 1; j <= t; ++j) {
                // Option 1: don't take arr[i-1]
                dp[i][j] = max(dp[i][j], dp[i-1][j]);
                // Option 2: take arr[i-1], then previous chosen must be from i-2 or before
                int idxPrev = max(0, i - 2); // use dp[idxPrev][j-1]
                if (dp[idxPrev][j-1] != NEG) {
                    dp[i][j] = max(dp[i][j], dp[idxPrev][j-1] + arr[i - 1]);
                }
            }
        }
        return dp[L][t];
    }

    int maxSizeSlices(vector<int>& slices) {
        int m = slices.size();              // m = 3n
        int n = m / 3;                      // number of picks we must make
        if (m == 0) return 0;
        if (m == 1) return slices[0];

        // Case 1: exclude last element => use [0 .. m-2]
        vector<int> arr1(slices.begin(), slices.end() - 1);
        long long res1 = solveLinear(arr1, n);

        // Case 2: exclude first element => use [1 .. m-1]
        vector<int> arr2(slices.begin() + 1, slices.end());
        long long res2 = solveLinear(arr2, n);

        long long ans = max(res1, res2);
        return (int)ans;
    }
};

// Example usage and quick tests
int main() {
    Solution sol;

    vector<int> s1 = {1,2,3,4,5,6};
    cout << "Expected 10, got: " << sol.maxSizeSlices(s1) << "\n";

    vector<int> s2 = {8,9,8,6,1,1};
    cout << "Expected 16, got: " << sol.maxSizeSlices(s2) << "\n";

    vector<int> s3 = {4,1,2,5,8,3,1,1,9}; // example with length 9 (3*n)
    cout << "Got: " << sol.maxSizeSlices(s3) << "\n";

    return 0;
}
