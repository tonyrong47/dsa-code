#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int> arr;
        int k = 1;
        arr.push_back(nums[0]);
        for (int i = 1; i <= nums.size() - 1; i++) {
            if (nums[i - 1] != nums[i]) {
                arr.push_back(nums[i]);
                k++;
            }
        }
        nums.assign(arr.begin(), arr.end());
        return k;
    }
};

int main() {
    Solution s;
    vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};

    cout << "Before: ";
    for (int n : nums) cout << n << " ";
    cout << endl;

    int k = s.removeDuplicates(nums);

    cout << "After (unique count = " << k << "): ";
    for (int n : nums) cout << n << " ";
    cout << endl;

    return 0;
}
