// Container With Most Water
// https://leetcode.com/problems/container-with-most-water/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0;
        int l = 0, r = height.size() - 1;
        while(l < r){
            int h = min(height[l],height[r]);
            ans = max(ans, h * (r - l));
            if(height[l] < height[r]) // 短板原理
                ++l;
            else 
                --r;
        }      
        return ans;
    }
};