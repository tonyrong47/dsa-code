#include <bits/stdc++.h>
using namespace std;

// Function to print duplicate elements in the array
void findDuplicates(vector<int>& nums) {
    unordered_map<int,int> freq;

    cout << "Duplicate elements are: ";
    bool hasDuplicate = false;

    for (int num : nums) {
        freq[num]++;
        if (freq[num] == 2) { // print only when it becomes duplicate
            cout << num << " ";
            hasDuplicate = true;
        }
    }

    if (!hasDuplicate) {
        cout << "none";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    findDuplicates(nums);

    return 0;
}
