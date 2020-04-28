//  Move Zeroes
// https://leetcode.com/problems/move-zeroes/

#include <bits/stdc++.h>
using namespace std;

// double pointer
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0,j = 0;i < n;i++){
            if(nums[i]){
                swap(nums[i], nums[j]);
                j++;// 慢指针，标记非0的尾巴
            }
        }
    }
};
