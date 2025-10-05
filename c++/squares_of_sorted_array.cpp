#include <bits/stdc++.h>
using namespace std;

/*
Problem: Given a sorted array, return a new array containing the squares of each number, also sorted.
Pattern: Two Pointers
*/

vector<int> sortedSquares(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n);
    int left = 0, right = n - 1;
    int pos = n - 1;

    while (left <= right) {
        if (abs(nums[left]) > abs(nums[right])) {
            result[pos] = nums[left] * nums[left];
            left++;
        } else {
            result[pos] = nums[right] * nums[right];
            right--;
        }
        pos--;
    }
    return result;
}

int main() {
    vector<int> nums = {-4, -1, 0, 3, 10};
    vector<int> res = sortedSquares(nums);

    cout << "Squared and sorted array: ";
    for (int val : res) cout << val << " ";
    cout << endl;

    return 0;
}
