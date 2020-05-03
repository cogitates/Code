// House Robber
// https://leetcode.com/problems/house-robber/

#include <bits/stdc++.h>
using namespace std;


// 如何考虑一个问题？(dp问题)
// 1. 如何缩小问题规模
// 2. 大规模和小规模问题的关系
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty()) return 0;
        vector<int> dp(nums.size(), 0);
        for(int i = 0;i < nums.size();i++){
            dp[i] = max((i > 1 ? dp[i-2] : 0) + nums[i],
                        (i > 0 ? dp[i-1] : 0));
        }
        return dp.back();
    }
};