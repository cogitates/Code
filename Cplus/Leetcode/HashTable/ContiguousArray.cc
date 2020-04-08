// Contiguous Array
// https://leetcode.com/problems/contiguous-array/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        // 0 1 0 ==> -1 1 -1
        unordered_map<int,int> mp;
        
        int res = 0; // answer
        int s = 0; // prefix-sum
        mp[0] = -1; // special case : prefix-sum = 0
        // mp[prefix-sum] = index
        for(int i = 0;i < nums.size();i++){
            s += nums[i] ? 1 : -1; // s是前缀和
            if(mp.count(s)) res = max(res,i-mp[s]);  // if re meet the prefix-sum s(0..j)
            else mp[s] = i; // remember first index s(0..i)
            // so that s(i,j) is the potential answer
        }
        return res;
    }
};