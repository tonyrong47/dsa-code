public class Solution {
    public int countDigitOne(int n) {
        int count = 0;

        for(long i = 1; i <= n; i *= 10) {
            long left = n / (i * 10);
            long current = (n / i) % 10;
            long right = n % i;

            if (current == 0) {
                count += left * i;
            } else if (current == 1) {
                count += left * i + right + 1;
            } else {
                count += (left + 1) * i;
            }
        }
        return count;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        int n1 = 13;
        int n2 = 0;

        System.out.println("Count of digit one up to " + n1 + " is: " + solution.countDigitOne(n1)); // Output: 6
        System.out.println("Count of digit one up to " + n2 + " is: " + solution.countDigitOne(n2)); // Output: 0
    }
}
