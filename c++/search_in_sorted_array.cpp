#include <iostream>
#include <vector>
using namespace std;

// Function to perform Binary Search
int searchInSortedArray(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2; // avoid overflow
        if (nums[mid] == target) {
            return mid; // found target
        } else if (nums[mid] < target) {
            left = mid + 1; // search right half
        } else {
            right = mid - 1; // search left half
        }
    }

    return -1; // target not found
}

int main() {
    // Example input
    vector<int> nums = {-1, 0, 3, 5, 9, 12};
    int target = 9;

    int result = searchInSortedArray(nums, target);

    if (result != -1)
        cout << "Target " << target << " found at index: " << result << endl;
    else
        cout << "Target " << target << " not found in the array." << endl;

    return 0;
}
