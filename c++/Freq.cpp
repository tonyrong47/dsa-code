#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maxFrequency(std::vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        long long total = 0;
        int left = 0, maxFreq = 0;

        for (int right = 0; right < nums.size(); ++right) {
            total += nums[right];

            while ((long long)(right - left + 1) * nums[right] - total > k) {
                total -= nums[left];
                left++;
            }

            maxFreq = max(maxFreq, right - left + 1);
        }

        return maxFreq;
    }
};