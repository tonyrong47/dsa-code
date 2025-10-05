package algorithms.strings;

import static org.junit.jupiter.api.Assertions.*;
import org.junit.jupiter.api.Test;

public class StringUtilsTest {

    @Test
    void testIsPalindrome() {
        assertTrue(StringUtils.isPalindrome("Madam"));
        assertTrue(StringUtils.isPalindrome("A man a plan a canal Panama"));
        assertFalse(StringUtils.isPalindrome("Hello"));
        assertFalse(StringUtils.isPalindrome(null));
    }

    @Test
    void testReverse() {
        assertEquals("olleH", StringUtils.reverse("Hello"));
        assertEquals("racecar", StringUtils.reverse("racecar"));
        assertNull(StringUtils.reverse(null));
    }

    @Test
    void testCountVowelsConsonants() {
        int[] result = StringUtils.countVowelsConsonants("Hello World");
        assertArrayEquals(new int[]{3, 7}, result); // 3 vowels, 7 consonants

        result = StringUtils.countVowelsConsonants("AEIOU");
        assertArrayEquals(new int[]{5, 0}, result);

        result = StringUtils.countVowelsConsonants("");
        assertArrayEquals(new int[]{0, 0}, result);

        result = StringUtils.countVowelsConsonants(null);
        assertArrayEquals(new int[]{0, 0}, result);
    }
}
