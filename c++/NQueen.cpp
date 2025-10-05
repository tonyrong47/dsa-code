#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> result;
        int n = nums.size();

        for (int i = 0; i < n - 2; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int target = -nums[i];
            
            int left = i + 1;
            int right = n - 1;

            while (left < right) {
                int sum = nums[left] + nums[right];

                if (sum == target) {
                    result.push_back({nums[i], nums[left], nums[right]});

                    int current_left_val = nums[left];
                    int current_right_val = nums[right];
                    
                    while (left < right && nums[left] == current_left_val) {
                        left++;
                    }
                    while (left < right && nums[right] == current_right_val) {
                        right--;
                    }
                } else if (sum < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }

        return result;
    }
};

int main() {
    Solution s;
    
    vector<int> nums1 = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> result1 = s.threeSum(nums1);
    cout << "Triplets for [-1, 0, 1, 2, -1, -4]:" << endl;
    for (const auto& triplet : result1) {
        cout << "[" << triplet[0] << ", " << triplet[1] << ", " << triplet[2] << "]" << endl;
    }
    cout << "---" << endl;

    vector<int> nums2 = {0, 0, 0};
    vector<vector<int>> result2 = s.threeSum(nums2);
    cout << "Triplets for [0, 0, 0]:" << endl;
    for (const auto& triplet : result2) {
        cout << "[" << triplet[0] << ", " << triplet[1] << ", " << triplet[2] << "]" << endl;
    }
    cout << "---" << endl;

    vector<int> nums3 = {-2, 0, 1, 1, 2};
    vector<vector<int>> result3 = s.threeSum(nums3);
    cout << "Triplets for [-2, 0, 1, 1, 2]:" << endl;
    for (const auto& triplet : result3) {
        cout << "[" << triplet[0] << ", " << triplet[1] << ", " << triplet[2] << "]" << endl;
    }
    
    return 0;
}