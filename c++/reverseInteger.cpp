#include <iostream>
#include <climits>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        long long rev = 0; 
        while (x != 0) {
            int digit = x % 10;
            rev = rev * 10 + digit;
            x /= 10;
            if (rev > INT_MAX || rev < INT_MIN) {
                return 0; 
            }
        }
        return (int)rev;
    }
};

int main() {
    int n;
    cout << "Enter an integer: ";
    cin >> n;

    Solution sol;
    int result = sol.reverse(n);

    cout << "Reversed integer: " << result << endl;
    return 0;
}
