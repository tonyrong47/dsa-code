#include <iostream>

long long power(long long base, long long exp, long long mod) {
    long long res = 1;
    base %= mod;

    while (exp > 0) {
        // If exp is odd, multiply base with result
        if (exp & 1) 
            res = (res * base) % mod;

        // exp must be even now
        exp >>= 1; // exp = exp / 2
        base = (base * base) % mod;
    }
    return res;
}

// Example
int main() {
    long long b = 2;
    long long e = 10;
    long long m = 1000;
    
    // Calculate (2^10) % 1000
    long long result = power(b, e, m);
    
    std::cout << "(" << b << "^" << e << ") % " << m << " = " << result << std::endl;
    
    return 0;
}