// Single Number
// https://leetcode.com/problems/single-number/


/*
Given a non-empty array of integers, every element appears twice except for one. Find that single one.

Note:

Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Example 1:

Input: [2,2,1]
Output: 1
Example 2:

Input: [4,1,2,1,2]
Output: 4
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto x : nums){
            mp[x]++;
        }
        int result;
        for(auto it = mp.begin();it!=mp.end();it++){
            if(it->second == 1){
                result = it->first;
            }
        }
        return result;
    }
};


class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for(auto num : nums){ 
            result ^= num; // 从二进制的状态角度考虑
            // ^异或操作，相同是0,不同是1
        }
        return result;
    }
};

int main(){
    Solution s;
    vector<int> v = {4,1,2,1,2};
    cout<<s.singleNumber(v)<<endl;
    return 0;
}