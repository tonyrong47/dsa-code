#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& A, vector<int>& B) {
        if (A.size() > B.size()) return findMedianSortedArrays(B, A);
        
        int m = A.size();
        int n = B.size();
        int l = 0;
        int r = m;
        
        while (l <= r) {
            int i = l + (r - l) / 2;
            int j = (m + n + 1) / 2 - i;
            
            long long L1 = i == 0 ? LLONG_MIN : A[i - 1];
            long long R1 = i == m ? LLONG_MAX : A[i];
            long long L2 = j == 0 ? LLONG_MIN : B[j - 1];
            long long R2 = j == n ? LLONG_MAX : B[j];
            
            if (L1 <= R2 && L2 <= R1) {
                int total_len = m + n;
                if (total_len % 2 == 0) {
                    return (max(L1, L2) + min(R1, R2)) / 2.0;
                } else {
                    return max(L1, L2);
                }
            } else if (L1 > R2) {
                r = i - 1;
            } else {
                l = i + 1;
            }
        }
        
        return 0.0;
    }
};

int main() {
    Solution s;
    
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};
    double median1 = s.findMedianSortedArrays(nums1, nums2);
    cout << "Median of nums1={1, 3} and nums2={2} is: " << median1 << endl;

    vector<int> nums3 = {1, 2};
    vector<int> nums4 = {3, 4};
    double median2 = s.findMedianSortedArrays(nums3, nums4);
    cout << "Median of nums3={1, 2} and nums4={3, 4} is: " << median2 << endl;

    vector<int> nums5 = {1, 2, 3, 4, 5};
    vector<int> nums6 = {};
    double median3 = s.findMedianSortedArrays(nums5, nums6);
    cout << "Median of nums5={1, 2, 3, 4, 5} and nums6={} is: " << median3 << endl;
    
    return 0;
}