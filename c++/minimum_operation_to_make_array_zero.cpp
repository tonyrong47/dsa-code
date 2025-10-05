// For each query [l, r] we consider the array nums = [l, l+1, ..., r].
// In one operation you pick two elements a and b from the array and replace them by floor(a/4) and floor(b/4) respectively.
// Find the minimum number of operations to make all elements of nums equal to 0. Return the sum of answers for all queries.

// Constraints:

// 1 <= queries.length <= 1e5

// 1 <= l < r <= 1e9

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minOperations(vector<vector<long long>>& queries) {
        long long totalAns = 0;

        for (auto &qr : queries) {
            long long l = qr[0];
            long long r = qr[1];

            long long S = 0; // total number of selections needed for interval [l,r]

            // iterate k where numbers with t = k are in [4^(k-1), 4^k - 1]
            // compute powers of 4 iteratively to avoid overflow
            long long lower = 1; // 4^(k-1) for k=1 -> 1
            for (int k = 1; ; ++k) {
                if (lower > r) break; // no numbers >= lower in [l,r], so stop

                // compute upper = 4^k - 1 safely; use multiplication check
                // upper = 4 * lower - 1  (since lower == 4^(k-1))
                // but ensure multiplication doesn't overflow 64-bit; r <= 1e9 so safe
                long long upper = lower * 4 - 1;

                long long segL = max(l, lower);
                long long segR = min(r, upper);
                if (segL <= segR) {
                    long long cnt = segR - segL + 1;
                    S += cnt * 1LL * k;
                }

                // prepare next lower = 4^k
                // if lower * 4 would overflow or exceed r dramatically we can still break early
                if (lower > (LLONG_MAX / 4)) break;
                lower *= 4;
            }

            // minimum operations for this query
            long long ops = (S + 1) / 2; // ceil(S/2)
            totalAns += ops;
        }

        return totalAns;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    if (!(cin >> q)) return 0;
    vector<vector<long long>> queries(q, vector<long long>(2));
    for (int i = 0; i < q; ++i) {
        cin >> queries[i][0] >> queries[i][1];
    }

    Solution sol;
    cout << sol.minOperations(queries) << '\n';
    return 0;
}