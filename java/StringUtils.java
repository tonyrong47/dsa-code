/**
 * StringUtils - Common String Utility Methods
 * 
 * Provides:
 * - Palindrome check
 * - Reverse string
 * - Count vowels and consonants
 * 
 * Author: Prince Yadav
 * Version: 1.0
 * Since: October 2025
 */
public class StringUtils {

    /**
     * Checks if a string is a palindrome (ignores case and spaces)
     * @param str input string
     * @return true if palindrome, false otherwise
     */
    public static boolean isPalindrome(String str) {
        if (str == null) return false;
        str = str.replaceAll("[^a-zA-Z0-9]", "").toLowerCase();
        int left = 0, right = str.length() - 1;
        while (left < right) {
            if (str.charAt(left) != str.charAt(right)) return false;
            left++;
            right--;
        }
        return true;
    }

    /**
     * Reverses the given string
     * @param str input string
     * @return reversed string
     */
    public static String reverse(String str) {
        if (str == null) return null;
        return new StringBuilder(str).reverse().toString();
    }

    /**
     * Counts vowels and consonants in a string
     * @param str input string
     * @return int array [vowelCount, consonantCount]
     */
    public static int[] countVowelsConsonants(String str) {
        int vowels = 0, consonants = 0;
        if (str != null) {
            str = str.toLowerCase();
            for (char c : str.toCharArray()) {
                if (c >= 'a' && c <= 'z') {
                    if ("aeiou".indexOf(c) != -1) vowels++;
                    else consonants++;
                }
            }
        }
        return new int[]{vowels, consonants};
    }
}
