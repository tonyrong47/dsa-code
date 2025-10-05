/**
 * MathUtils - Common mathematical helper functions
 * Author: Prince Yadav
 * @version 1.0
 * @since October 2025
 */
public class MathUtils {

    // GCD using Euclidean Algorithm
    public static int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    // LCM using GCD
    public static int lcm(int a, int b) {
        return (a / gcd(a, b)) * b;
    }

    // Check if number is prime
    public static boolean isPrime(int n) {
        if (n <= 1) return false;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) return false;
        }
        return true;
    }
}
