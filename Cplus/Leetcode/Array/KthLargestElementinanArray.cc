// Kth Largest Element in an Array
// https://leetcode.com/problems/kth-largest-element-in-an-array/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq(nums.begin(), nums.begin()); // 默认小顶堆
        for(int i = 0;i < k - 1;i++){
            pq.pop();
        }
        return pq.top();
    }
};