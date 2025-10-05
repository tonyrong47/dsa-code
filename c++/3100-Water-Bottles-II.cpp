// POTD on Leetcode on 2 OCTBOBER 2025

class Solution {
public:
    static int isqrt(int n) {
        int x = n, c = 0;
        // Largest power of 4 <= our largest possible value for n
        int d = 1 << 14;
        while (d > n) {
            d >>= 2;
        }
        while (d != 0) {
            if (x >= c + d) {
                x -= c + d;
                c = (c >> 1) + d;
            } else {
                c >>= 1;
            }
            d >>= 2;
        }
        return c;
    }

    static int maxBottlesDrunk(int numBottles, int numExchange) {
        int b = 2 * numExchange - 3;
        int delta = b * b + 8 * numBottles;
        int deltasqrt = isqrt(delta);
        int root = (deltasqrt - b) >> 1;
        return numBottles + root - (deltasqrt * deltasqrt == delta);
    }
};