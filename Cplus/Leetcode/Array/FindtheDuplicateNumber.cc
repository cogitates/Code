// Find the Duplicate Number
// https://leetcode.com/problems/find-the-duplicate-number/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0, fast = 0, t = 0;
        while(true){
            slow = nums[slow];
            fast = nums[nums[fast]];
            if(slow == fast) break;
        }// when break --> slow == fast
        while(true){
            slow = nums[slow];
            t = nums[t];
            if(slow == t) break;
        }
        return slow;
    }
};