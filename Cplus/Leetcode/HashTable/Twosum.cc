// Two Sum
// https://leetcode.com/problems/two-sum/
#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<int> twoSum(vector<int>& nums,int target){
        unordered_map<int,int> mp;
        for(int i = 0;i < nums.size();i++){
            int t = target - nums[i];
            if(mp.count(t)) return vector<int>({mp[t],i});
            mp[nums[i]] = i;
        }

        return vector<int>{};
    }
};
