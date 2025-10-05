/**
 * @file SuffixArrayLCP.cpp
 * @brief Implementation of Suffix Array with LCP (Longest Common Prefix) Array
 * @author Hacktoberfest Contributor
 * @date October 2025
 *
 * Problem: Build suffix array and LCP array for efficient string operations
 *
 * Suffix Array: Array of integers representing starting positions of all suffixes
 * of a string, sorted in lexicographical order.
 *
 * LCP Array: Array where lcp[i] = length of longest common prefix between
 * suffix[i] and suffix[i-1] in the sorted suffix array.
 *
 * Algorithm: O(N log N) construction using radix sort and doubling technique
 * - Start by sorting suffixes by first character
 * - Double the comparison length each iteration
 * - Use pair sorting and rank compression
 * - Build LCP using Kasai's algorithm in O(N)
 *
 * Key Insight: Instead of comparing full suffixes (O(N) each), use precomputed
 * ranks from previous iteration, reducing comparison to O(1).
 *
 * Time Complexity:
 * - Suffix Array Construction: O(N log² N) with std::sort, O(N log N) with radix sort
 * - LCP Construction: O(N)
 * Space Complexity: O(N)
 *
 * Applications:
 * - Pattern matching (find all occurrences in O(M log N))
 * - Longest repeated substring
 * - Longest common substring of multiple strings
 * - Number of distinct substrings
 * - String comparison and ranking
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class SuffixArray {
private:
    string text;              // Input string
    int n;                    // Length of string
    vector<int> suffixArr;    // Suffix array
    vector<int> lcp;          // LCP array

    /**
     * @brief Build suffix array using O(N log² N) algorithm
     *
     * Algorithm:
     * 1. Start with length 1 (sort by first character)
     * 2. Double length each iteration: 1 -> 2 -> 4 -> 8 -> ...
     * 3. For each length, sort suffixes by (rank[i], rank[i+len])
     * 4. Recompute ranks based on new order
     * 5. Stop when length >= N
     */
    void buildSuffixArray() {
        // Suffix structure for sorting
        struct Suffix {
            int index;      // Original index
            int rank[2];    // Current rank and rank at offset

            bool operator<(const Suffix& other) const {
                if (rank[0] != other.rank[0])
                    return rank[0] < other.rank[0];
                return rank[1] < other.rank[1];
            }
        };

        vector<Suffix> suffixes(n);

        // Initialize ranks with ASCII values
        for (int i = 0; i < n; i++) {
            suffixes[i].index = i;
            suffixes[i].rank[0] = text[i];
            suffixes[i].rank[1] = (i + 1 < n) ? text[i + 1] : -1;
        }

        // Sort by first two characters
        sort(suffixes.begin(), suffixes.end());

        // Temporary rank array
        vector<int> tempRank(n);

        // Double the length each iteration
        for (int len = 2; len < 2 * n; len *= 2) {
            // Assign new ranks based on sorted order
            int rank = 0;
            int prevRank0 = suffixes[0].rank[0];
            int prevRank1 = suffixes[0].rank[1];
            suffixes[0].rank[0] = 0;
            tempRank[suffixes[0].index] = 0;

            for (int i = 1; i < n; i++) {
                // If current suffix has different rank pair than previous,
                // increment rank
                if (suffixes[i].rank[0] != prevRank0 ||
                    suffixes[i].rank[1] != prevRank1) {
                    rank++;
                    prevRank0 = suffixes[i].rank[0];
                    prevRank1 = suffixes[i].rank[1];
                }

                suffixes[i].rank[0] = rank;
                tempRank[suffixes[i].index] = rank;
            }

            // Update rank[1] for next iteration
            for (int i = 0; i < n; i++) {
                int nextIndex = suffixes[i].index + len;
                suffixes[i].rank[1] = (nextIndex < n) ? tempRank[nextIndex] : -1;
            }

            // Sort by new ranks
            sort(suffixes.begin(), suffixes.end());
        }

        // Store suffix array
        suffixArr.resize(n);
        for (int i = 0; i < n; i++) {
            suffixArr[i] = suffixes[i].index;
        }
    }

    /**
     * @brief Build LCP array using Kasai's algorithm in O(N)
     *
     * Key Insight: If lcp of suffix[i] and suffix[i-1] is k,
     * then lcp of suffix[i+1] and its predecessor is at least k-1.
     *
     * Algorithm:
     * 1. For each suffix in text order (not sorted order)
     * 2. Find its position in suffix array
     * 3. Compare with previous suffix in sorted order
     * 4. Use previous LCP value - 1 as starting point
     */
    void buildLCP() {
        lcp.resize(n, 0);

        // inv[i] = position of suffix starting at i in suffix array
        vector<int> inv(n);
        for (int i = 0; i < n; i++) {
            inv[suffixArr[i]] = i;
        }

        int k = 0;  // Length of current LCP

        for (int i = 0; i < n; i++) {
            if (inv[i] == 0) {
                k = 0;
                continue;
            }

            // Find previous suffix in sorted order
            int j = suffixArr[inv[i] - 1];

            // Extend LCP from previous value
            while (i + k < n && j + k < n && text[i + k] == text[j + k]) {
                k++;
            }

            lcp[inv[i]] = k;

            // Decrease k by 1 for next iteration (Kasai's optimization)
            if (k > 0) k--;
        }
    }

public:
    /**
     * @brief Constructor - build suffix array and LCP
     * @param s Input string
     */
    SuffixArray(const string& s) : text(s), n(s.length()) {
        buildSuffixArray();
        buildLCP();
    }

    /**
     * @brief Get suffix array
     */
    vector<int> getSuffixArray() const {
        return suffixArr;
    }

    /**
     * @brief Get LCP array
     */
    vector<int> getLCP() const {
        return lcp;
    }

    /**
     * @brief Print suffix array with suffixes
     */
    void printSuffixArray() {
        cout << "\nSuffix Array:" << endl;
        cout << "Index | Position | LCP | Suffix" << endl;
        cout << "------|----------|-----|-------" << endl;

        for (int i = 0; i < n; i++) {
            cout.width(5);
            cout << i << " | ";
            cout.width(8);
            cout << suffixArr[i] << " | ";
            cout.width(3);
            cout << lcp[i] << " | ";
            cout << text.substr(suffixArr[i]) << endl;
        }
    }

    /**
     * @brief Find pattern using binary search on suffix array
     * @param pattern Pattern to search
     * @return Starting indices of all occurrences
     *
     * Time Complexity: O(M log N) where M = pattern length
     */
    vector<int> search(const string& pattern) {
        vector<int> result;
        int m = pattern.length();

        // Binary search for lower bound
        int left = 0, right = n - 1;
        int lower = -1;

        while (left <= right) {
            int mid = (left + right) / 2;
            string suffix = text.substr(suffixArr[mid], min(m, n - suffixArr[mid]));

            if (suffix >= pattern) {
                if (suffix.substr(0, m) == pattern) {
                    lower = mid;
                }
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        if (lower == -1) return result;  // Pattern not found

        // Find all occurrences
        for (int i = lower; i < n; i++) {
            if (text.substr(suffixArr[i], m) == pattern) {
                result.push_back(suffixArr[i]);
            } else {
                break;
            }
        }

        sort(result.begin(), result.end());
        return result;
    }

    /**
     * @brief Find longest repeated substring
     * @return Longest substring that appears at least twice
     *
     * Algorithm: Find maximum value in LCP array
     */
    string longestRepeatedSubstring() {
        int maxLen = 0;
        int maxIndex = 0;

        for (int i = 1; i < n; i++) {
            if (lcp[i] > maxLen) {
                maxLen = lcp[i];
                maxIndex = suffixArr[i];
            }
        }

        if (maxLen == 0) return "";
        return text.substr(maxIndex, maxLen);
    }

    /**
     * @brief Count number of distinct substrings
     * @return Total distinct substrings
     *
     * Formula: Total substrings - Duplicate substrings
     *        = n*(n+1)/2 - sum(lcp[i])
     */
    long long countDistinctSubstrings() {
        long long total = (long long)n * (n + 1) / 2;

        for (int i = 0; i < n; i++) {
            total -= lcp[i];
        }

        return total;
    }

    /**
     * @brief Find longest common substring between two strings
     * @param s1 First string
     * @param s2 Second string
     * @return Longest common substring
     *
     * Algorithm: Concatenate s1 + "#" + s2, build suffix array,
     * find max LCP where adjacent suffixes come from different strings
     */
    static string longestCommonSubstring(const string& s1, const string& s2) {
        string combined = s1 + "#" + s2;
        SuffixArray sa(combined);

        int maxLen = 0;
        int maxIndex = 0;
        int n1 = s1.length();
        int n2 = combined.length();

        vector<int> suffixes = sa.getSuffixArray();
        vector<int> lcps = sa.getLCP();

        for (int i = 1; i < combined.length(); i++) {
            // Check if adjacent suffixes are from different strings
            bool diff = (suffixes[i-1] < n1) != (suffixes[i] < n1);

            if (diff && lcps[i] > maxLen) {
                maxLen = lcps[i];
                maxIndex = suffixes[i];
            }
        }

        if (maxLen == 0) return "";
        return combined.substr(maxIndex, maxLen);
    }
};

/**
 * @brief Example usage and test cases
 */
int main() {
    // Test Case 1: Basic suffix array
    cout << "=== Test Case 1: Basic Suffix Array ===" << endl;
    string text1 = "banana";
    SuffixArray sa1(text1);
    sa1.printSuffixArray();

    // Test Case 2: Pattern search
    cout << "\n=== Test Case 2: Pattern Searching ===" << endl;
    string text2 = "abracadabra";
    SuffixArray sa2(text2);

    string pattern = "abra";
    vector<int> occurrences = sa2.search(pattern);

    cout << "Text: " << text2 << endl;
    cout << "Pattern: " << pattern << endl;
    cout << "Found at positions: ";
    for (int pos : occurrences) {
        cout << pos << " ";
    }
    cout << endl;

    // Test Case 3: Longest repeated substring
    cout << "\n=== Test Case 3: Longest Repeated Substring ===" << endl;
    string text3 = "abcabcabc";
    SuffixArray sa3(text3);

    string lrs = sa3.longestRepeatedSubstring();
    cout << "Text: " << text3 << endl;
    cout << "Longest repeated substring: " << lrs << endl;

    // Test Case 4: Count distinct substrings
    cout << "\n=== Test Case 4: Count Distinct Substrings ===" << endl;
    string text4 = "aaa";
    SuffixArray sa4(text4);

    long long count = sa4.countDistinctSubstrings();
    cout << "Text: " << text4 << endl;
    cout << "Number of distinct substrings: " << count << endl;
    // Expected: "", "a", "aa", "aaa" = 4 distinct

    // Test Case 5: Longest common substring
    cout << "\n=== Test Case 5: Longest Common Substring ===" << endl;
    string s1 = "GeeksforGeeks";
    string s2 = "GeeksQuiz";

    string lcs = SuffixArray::longestCommonSubstring(s1, s2);
    cout << "String 1: " << s1 << endl;
    cout << "String 2: " << s2 << endl;
    cout << "Longest common substring: " << lcs << endl;

    // Test Case 6: Complex example
    cout << "\n=== Test Case 6: Multiple Patterns ===" << endl;
    string text6 = "mississippi";
    SuffixArray sa6(text6);

    sa6.printSuffixArray();

    vector<string> patterns = {"issi", "ss", "pi"};
    for (const string& p : patterns) {
        vector<int> pos = sa6.search(p);
        cout << "\nPattern '" << p << "' found at: ";
        if (pos.empty()) {
            cout << "Not found";
        } else {
            for (int i : pos) cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}
