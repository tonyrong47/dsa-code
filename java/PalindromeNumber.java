class Solution {
    public static boolean isPalindrome(int x) {
        if (x < 0) return false; // negative numbers are not palindrome

        int r, sum = 0;
        int temp = x;

        while (x > 0) {
            r = x % 10;
            sum = (sum * 10) + r;
            x = x / 10;
        }

        return temp == sum;
    }

    public static void main(String[] args) {
        int x = 121;
        System.out.println(isPalindrome(x)); // true
    }
}
