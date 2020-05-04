// Subsets
// https://leetcode.com/problems/subsets/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> cur;
        // n is size of cur
        // s is start of the tree
        for(int i = 0;i <= nums.size();++i){ // 这里是对4棵树进行了遍历
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

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> cur;

        dfs(nums,0,cur,ans);
        return ans;
    }
private:
    // 遍历的树是组合树，不同于组合问题结果大小固定，子集问题包括所有大小的组合情况
    void dfs(const vector<int>& nums,int s,vector<int>& cur,vector<vector<int>>& ans){
        // cout<<n<<":"<<s<<":"<<cur.size()<<endl;
        ans.push_back(cur);
        for(int i = s;i < nums.size();++i){
            cur.push_back(nums[i]);
            dfs(nums, i+1, cur, ans);
            cur.pop_back();
        }
    }
};