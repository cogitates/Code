// Top K Frequent Elements
// https://leetcode.com/submissions/detail/335130526/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        priority_queue<pair<int,int>> q;
        vector<int> res;
        for(auto a : nums) ++m[a];
        for(auto it : m) q.push({it.second,it.first});
        for(int i = 0;i < k;++i){
            res.push_back(q.top().second);
            q.pop();
        }
        return res;
    }
};