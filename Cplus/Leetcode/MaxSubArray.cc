// Maximum Subarray 
// https://leetcode.com/problems/maximum-subarray
#include <bits/stdc++.h>
using namespace std;

// this solution is wrong
class Solution1 {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp(nums.size());
        dp[0] = nums.at(0);

        for(int i = 1;i < nums.size();i++){
            dp[i] = std::max(dp[i-1] + nums[i],nums[i]);
        }

        return *std::max_element(dp.begin(),dp.end());
    }
};


class Solution2 {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = nums[0];
        int curMax = nums[0];
        for(int i = 1;i < nums.size();i++){
            curMax = std::max(curMax+nums[i],nums[i]);
            if(curMax > ans)
                ans = curMax;
        }
        return ans;
    }
};


class Solution3{
public:
    int maxSubArray(vector<int>& nums){
        int n = nums.size();
        return help(nums,0,n-1);
    }
    int help(const vector<int>& nums,int lo,int hi){
        if(lo == hi)
            return nums[lo];
        int mid = (lo + hi) >> 1;

        int lmax = nums[mid],lsum = 0;
        int rmax = nums[mid+1],rsum = 0;

        for(int i = mid;i >= lo;i--){
            lsum += nums[i];
            lmax = max(lmax,lsum);
        }

        for(int i = mid+1;i <= hi;i++){
            rsum += nums[i];
            rmax = max(rmax,rsum);
        }

        return max(max(help(nums,lo,mid),help(nums,mid+1,hi)),lmax+rmax);
    }
};