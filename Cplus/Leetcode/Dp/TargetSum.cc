// Target Sum
// https://leetcode.com/problems/target-sum/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        const int n = nums.size();
        const int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum < S) return 0;
        const int offset = sum;// 设置offset 是因为有加法和减法两个方向
        vector<vector<int>> ways(n+1, vector<int>(sum+offset+1,0));
        ways[0][offset] = 1;
        for(int i = 0;i < n;++i){
            for(int j = nums[j]; j < 2 * sum + 1 - nums[i];++j){
                if(ways[i][j]){
                    ways[i+1][j+nums[i]] += ways[i][j];
                    ways[i+1][j-nums[i]] += ways[i][j];
                }
            }
            return ways.back()[S+offset];
        }
    }
};

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        const int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum < abs(S))  return 0;
        int ans = 0;
        dfs(nums, 0, S, ans);
        return ans;
    }
private:
    void dfs(const vector<int>& nums,int d,int S, int& ans){
        if(d == nums.size()){
            if(S == 0) ++ans;
            return ;
        }
        dfs(nums, d+1, S-nums[d],ans);
        dfs(nums, d+1, S+nums[d],ans);
    }
};
