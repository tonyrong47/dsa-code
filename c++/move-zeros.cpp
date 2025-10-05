#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0;
        for(int j = 0; j < nums.size(); j++){
            if(nums[j] != 0 ){
                nums[i] = nums[j];
                i++;
            }
        }
        for(; i < nums.size(); i++){
            nums[i] = 0;
        }
    }
};

int main() {
    Solution s;
    vector<int> nums = {0, 1, 0, 3, 12};

    cout << "Before: ";
    for (int n : nums) cout << n << " ";
    cout << endl;

    s.moveZeroes(nums);

    cout << "After: ";
    for (int n : nums) cout << n << " ";
    cout << endl;

    return 0;
}
