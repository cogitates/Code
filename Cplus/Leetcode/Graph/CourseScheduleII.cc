// Course Schedule II
// https://leetcode.com/problems/course-schedule-ii/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        graph = vector<vector<int> >(numCourses); // 邻接链表
        for(const auto& p: prerequisites)
            graph[p[0]].push_back(p[1]);
        
        // states : 0 = unknown, 1 = visiting, 2 = visited
        vector<int> v(numCourses,0); // state array
        vector<int> ans;
        for(int i = 0;i < numCourses;i++){ // 前面访问过的点，后面不应该再被访问到
            if(dfs(i,v,graph,ans)) return {}; // 若前面访问到的点后面又被访问到，那么就说这里有环,有环则没有答案
        }
        
        return ans;
    }
private:
    vector<vector<int> > graph;
    bool dfs(int cur, vector<int>& v,vector<vector<int>>& graph,vector<int>& ans){
        if(v[cur] == 1) return true; // 若访问到了visiting，说明有环
        if(v[cur] == 2) return false;// 访问visited,无环,但是图的联通性变强了
        
        v[cur] = 1; // 当前点标记为正在访问中
        
        for(const int t : graph[cur])
            if(dfs(t,v,graph,ans)) return true; // 有环
        
        v[cur] = 2; // 更新状态
        ans.push_back(cur); // 节点是安全的，加入ans
        return false; // 无环
    }
};