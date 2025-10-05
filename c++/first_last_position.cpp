#include <bits/stdc++.h>
using namespace std;

/*
Problem: Find the first and last positions of a target element in a sorted array.
Pattern: Binary Search (lower bound/upper bound)
*/

int lowerBound(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1, ans = -1;
    while (left <= right) {
        int mid = left + (right - left)/2;
        if (nums[mid] == target) { ans = mid; right = mid - 1; }
        else if (nums[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return ans;
}

int upperBound(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1, ans = -1;
    while (left <= right) {
        int mid = left + (right - left)/2;
        if (nums[mid] == target) { ans = mid; left = mid + 1; }
        else if (nums[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return ans;
}

int main() {
    vector<int> nums = {5,7,7,8,8,10};
    int target = 8;

    int first = lowerBound(nums, target);
    int last = upperBound(nums, target);

    cout << "First position: " << first << ", Last position: " << last << endl;

    return 0;
}
