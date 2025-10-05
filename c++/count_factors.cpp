#include <bits/stdc++.h>
using namespace std;

/*
Problem: Count the total number of factors of a given number n.
Pattern: Number Theory
*/

int countFactors(int n) {
    int count = 0;
    for (int i = 1; i*i <= n; i++) {
        if (n % i == 0) {
            if (i == n/i) count++; // perfect square
            else count += 2; // i and n/i
        }
    }
    return count;
}

int main() {
    int n = 36;
    cout << "Number of factors of " << n << ": " << countFactors(n) << endl;
    return 0;
}
