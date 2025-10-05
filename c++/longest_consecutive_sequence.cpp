//Add Longest Consecutive Sequence problem in C++ (LeetCode 128)

#include <bits/stdc++.h>
using namespace std;

int longestConsecutive(vector<int>& nums) {
    unordered_set<int> s(nums.begin(), nums.end());
    int longestStreak = 0;

    for (int num : nums) {
        if (s.find(num - 1) == s.end()) { // start of a sequence
            int currentNum = num;
            int currentStreak = 1;

            while (s.find(currentNum + 1) != s.end()) {
                currentNum++;
                currentStreak++;
            }
            longestStreak = max(longestStreak, currentStreak);
        }
    }
    return longestStreak;
}

int main() {
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    cout << "Longest Consecutive Sequence Length: " << longestConsecutive(nums) << endl;
    return 0;
}
