// Subsets
// https://leetcode.com/problems/subsets/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> cur;

        for(int i = 0;i <= nums.size();++i){
            dfs(nums,i,0,cur,ans); 
        }
        return ans;
    }
private:
    void dfs(const vector<int>& nums,int n,int s,vector<int>& cur,vector<vector<int>>& ans){
        if(n == cur.size()){ // n is the length
            ans.push_back(cur);
        }
        // s is the begin
        for(int i = s;i < nums.size();++i){
            cur.push_back(nums[i]);
            dfs(nums, n, i+1, cur, ans);
            cur.pop_back();
        }
    }
};