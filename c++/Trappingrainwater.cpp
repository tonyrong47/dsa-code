#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& h) {
        int n=h.size(),l=0,r=n-1,lm=0,rm=0,ans=0;
        while(l<r){
            if(h[l]<h[r]){
                if(h[l]>=lm) lm=h[l];
                else ans+=lm-h[l];
                l++;
            }else{
                if(h[r]>=rm) rm=h[r];
                else ans+=rm-h[r];
                r--;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> h = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << sol.trap(h) << endl; // Expected output: 6
    return 0;
}
