// Product of Array Except Self
// https://leetcode.com/problems/product-of-array-except-self/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(n,1),b(n,1),res(n);
        for(int i = 0;i < n-1;i++){
            f[i+1] = f[i] * nums[i];
        }
        for(int i = n - 1;i > 0;i--){
            b[i-1] = b[i] * nums[i];
        }
        
        for(int i = 0;i < n;i++){
            res[i] = f[i] * b[i];
        }
        return res;
    }
};