// Longest Increasing Subsequence
// https://leetcode.com/problems/longest-increasing-subsequence/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)  return 0;
        f = vector<int>(n,0);
        int ans = 0;
        for(int i = 0;i < n;i++){ //以某个点为结尾的最长递增子序列
            ans = max(ans,LIS(nums,i));
        }
        return ans;
    }
private:
    vector<int> f;
    int LIS(const vector<int>& nums, int r){ //利用f来计算最长递增子序列 
        if(r == 0) return 1;
        if(f[r] > 0) return f[r];
        int ans = 1;
        for(int i = 0;i < r;i++){
            if(nums[r] > nums[i])
                ans = max(ans, LIS(nums,i)+1);
        }
        f[r] = ans;
        return f[r];
    }
};

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(n,0);
        for(int i = 0;i < n;i++){
            for(int j = 0;j <= i;j++){
                if(nums[i] > nums[j]){
                    f[i] = max(f[i], f[j]+1);
                }
            }
        }
        return *max_element(f.begin(), f.end());
    }
};