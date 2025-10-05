#include <iostream>
using namespace std;

// Function to compute the integer square root using Binary Search
int mySqrt(int x) {
    if (x == 0 || x == 1) return x;

    int left = 1, right = x, ans = 0;

    while (left <= right) {
        long long mid = left + (right - left) / 2; // use long long to avoid overflow
        long long sq = mid * mid;

        if (sq == x) {
            return mid; // perfect square
        } else if (sq < x) {
            ans = mid;   // mid is a possible answer
            left = mid + 1; // search in right half
        } else {
            right = mid - 1; // search in left half
        }
    }
    return ans; // integer part of sqrt(x)
}

int main() {
    int x;
    cout << "Enter a number: ";
    cin >> x;

    cout << "Square root of " << x << " is " << mySqrt(x) << endl;

    return 0;
}
