import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

public class MathUtilsTest {

    @Test
    void testGcd() {
        assertEquals(6, MathUtils.gcd(54, 24));
    }

    @Test
    void testLcm() {
        assertEquals(216, MathUtils.lcm(54, 24));
    }

    @Test
    void testIsPrime() {
        assertTrue(MathUtils.isPrime(7));
        assertFalse(MathUtils.isPrime(10));
    }
}
