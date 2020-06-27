// Find All Numbers Disappeared in an Array
// https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        for(int i = 0;i < nums.size();i++){
            if(nums[i] != nums[nums[i]-1]){
                swap(nums[i],nums[nums[i]-1]);
                --i;
            }
        }
        
        for(int i = 0;i < nums.size();i++){
            if(nums[i] != i+1){
                res.push_back(i+1);
            }
        }
        // print(nums);
        return res;
    }
    void print(vector<int>& nums){
        for(int i = 0;i < nums.size();i++){
            cout<<nums[i]<<" ";
        }
    }
};