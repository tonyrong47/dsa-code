// Given an input string (s) and a pattern (p), implement wildcard pattern matching with support 
// for '?' and '*' where: '?' Matches any single character. '*' Matches any sequence of characters 
// (including the empty sequence). The matching should cover the entire input string (not partial).

public class wildcard {
    public boolean isMatch(String s, String p) {
        int n = s.length();
        int m = p.length();

        int i = 0; // pointer for s
        int j = 0; // pointer for p
        int starIdx = -1; // most recent position of '*' in p, -1 if none
        int iAfterStar = -1; // position in s corresponding to how many chars '*' has consumed

        while (i < n) {
            // Case 1: characters match or pattern has '?'
            if (j < m && (p.charAt(j) == '?' || p.charAt(j) == s.charAt(i))) {
                i++;
                j++;
            }
            // Case 2: pattern has '*' — record its position and try to match zero
            // characters first
            else if (j < m && p.charAt(j) == '*') {
                starIdx = j;
                iAfterStar = i;
                j++; // move past '*', try matching zero characters initially
            }
            // Case 3: mismatch but we previously saw a '*' — backtrack: let '*' consume one
            // more character
            else if (starIdx != -1) {
                // expand the area matched by last '*' by one more char
                iAfterStar++;
                i = iAfterStar;
                j = starIdx + 1; // resume matching just after the '*'
            }
            // Case 4: mismatch and no previous '*' to adjust -> no match
            else {
                return false;
            }
        }

        // consume remaining '*' in pattern (they can match empty sequences)
        while (j < m && p.charAt(j) == '*')
            j++;

        // if pattern fully consumed, it's a match
        return j == m;
    }

    // Optional: quick manual test harness
    public static void main(String[] args) {
        wildcard sol = new wildcard();
        System.out.println(sol.isMatch("aa", "a")); // false
        System.out.println(sol.isMatch("aa", "*")); // true
        System.out.println(sol.isMatch("cb", "?a")); // false
        System.out.println(sol.isMatch("", "*")); // true
        System.out.println(sol.isMatch("", "")); // true
        System.out.println(sol.isMatch("abcd", "a*d")); // true
    }
}
