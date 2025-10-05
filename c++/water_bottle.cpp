//leetcode 1518 problem
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static int exchange(int n, int k) {
        if (n < k) return 0;
        div_t qr = div(n, k);   // quotient & remainder
        int n0 = qr.quot;
        int r  = qr.rem;
        return n0 + exchange(n0 + r, k);
    }

    static int numWaterBottles(int n, int k) {
        return n + exchange(n, k);
    }
};

int main() {
    int n, k;
    cout << "Enter number of bottles and exchange rate: ";
    cin >> n >> k;

    cout << "Maximum bottles you can drink: "
         << Solution::numWaterBottles(n, k) << endl;

    return 0;
}
