#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        /* int n = nums.size();
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                if (nums[i] + nums[j] == target) {
                    ans.push_back(i);
                    ans.push_back(j);
                }
            }
        }
        return ans; */

        // Optimal
        /* unordered_map<int, int> num_map; // Map to store number and its index
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i]; // Calculate the complement

            // Check if the complement exists in the map
            if (num_map.find(complement) != num_map.end()) {
                ans.push_back(
                    num_map[complement]); // Add the index of the complement
                ans.push_back(i);         // Add the current index
                return ans; // Return the answer as soon as we find it
            }

            // Store the current number and index in the map
            num_map[nums[i]] = i;
        }

        return ans; */

        /* vector<int> ans;
        
        unordered_map<int,int> map;
        int n = nums.size();
        for(int i = 0;i<n;i++){
           map[nums[i]] = i;
        }

        for(int i = 0;i<n;i++){
            int rem = target - nums[i];
            if(map.find(rem) != map.end() && map[rem] != i){
                ans.push_back(i);
                ans.push_back(map[rem]);
                
                return ans;
            }
        }
        return ans; */


        /* unordered_map<int,int> map;
        int n = nums.size();

        for(int i = 0;i<n;i++){
            int complement = target - nums[i];
            if(map.find(complement) != map.end()){
                return {map[complement],i};
            }
            map[nums[i]] = i;
        }
        return {}; */



        vector<int> ans;
        unordered_map<int,int> map;
        int n = nums.size();

        for(int i = 0;i<n;i++){
            map[nums[i]] = i;
        }

        for(int i = 0;i<n;i++){
            int complement = target - nums[i];
            if(map.find(complement) != map.end() && map[complement] != i /* edge case */){
                ans.push_back(map[complement]);
                ans.push_back(i);
                return ans;
            }

        }
        return ans;
    }
};

int main(){
    Solution sol;
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i = 0;i<n;i++){
        cin>>nums[i];
    }
    int target;
    cin>>target;
    vector<int> result = sol.twoSum(nums,target);
    cout<<"[";
    for(int i = 0;i<result.size();i++){
        cout<<result[i]<<",";
    }
    cout<<"]"<<endl;
    return 0;
}

