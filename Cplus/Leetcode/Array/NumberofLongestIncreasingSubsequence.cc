// Number of Longest Increasing Subsequence
// https://leetcode.com/problems/number-of-longest-increasing-subsequence/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int res = 0;
        int n = nums.size();
        int mx = 0;
        vector<int> len(n, 1), cnt(n, 1);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                // 对于i&&j ==> (nums[i]&&nums[j] len[i]&&len[j] cnt[i]&&cnt[j]) 
                // 通过对上面几种状态的处理，从而解决问题
                if (nums[i] <= nums[j]) continue; // 1. 什么都不做
                if (len[i] == len[j] + 1) cnt[i] += cnt[j]; // 2.1 更新 若长度情况与上次相同，则更新数量
                else if (len[i] < len[j] + 1) { // 2.2 更新 若新长度大于原长度，则更新长度，重置数量
                    len[i] = len[j] + 1;
                    cnt[i] = cnt[j];
                }
            }
            if (mx == len[i]) res += cnt[i];
            else if (mx < len[i]) {
                mx = len[i];
                res = cnt[i];
            }
        }
        return res;
    }
};