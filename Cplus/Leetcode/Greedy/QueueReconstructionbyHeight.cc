// Queue Reconstruction by Height
// https://leetcode.com/problems/queue-reconstruction-by-height/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(),people.end(),[](vector<int>& a, vector<int>& b){
            return a[0] > b[0] || (a[0] == b[0] && a[1] < b[1]);
            // 优先按照身高排序，身高相同按照位序排序
        });
        // after sorted:
        // [[7,0],[7,1],[6,1],[5,0],[5,2],[4,4]]
        vector<vector<int>> res;
        for(auto a : people){
            // 逐个插入，按照位序,先插入的不影响前面插入的，但是影响后面插入的 <== 本质逻辑
            // cout<<a[1]<<" ";
            res.insert(res.begin() + a[1],a);
            
        }
        
        return res;
    }
};

