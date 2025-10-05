/**
 * A utility class to reverse an integer.
 * Handles both positive and negative integers.
 */
public class ReverseInteger {

    /**
     * Reverses the digits of the given integer.
     *
     * @param x the integer to reverse
     * @return the reversed integer
     */
    public static long reverse(long x) {
        long reversed = 0;
        while (x != 0) {
            reversed = reversed * 10 + x % 10; // Extract the last digit and add it to the reversed number
            x = x / 10; // Remove the last digit from the original number
        }
        return reversed;
    }

    public static void main(String[] args) {
        // Test cases
        int positiveNumber = 123;
        int negativeNumber = -123;
        int numberWithTrailingZero = 120;

        // Reverse the numbers
        long reversedPositive = reverse(positiveNumber);
        long reversedNegative = reverse(negativeNumber);
        long reversedTrailingZero = reverse(numberWithTrailingZero);

        // Print the results
        System.out.println("Reversed " + positiveNumber + ": " + reversedPositive);
        System.out.println("Reversed " + negativeNumber + ": " + reversedNegative);
        System.out.println("Reversed " + numberWithTrailingZero + ": " + reversedTrailingZero);
    }
}
