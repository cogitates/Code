// Permutations
// https://leetcode.com/problems/permutations/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        if(nums.size() == 0)  return result;
        vector<bool> visited(nums.size(),false);// 对路径选择的一种抽象,visited[]随着路径的增长而更新
        vector<int> temp;// temp保存的是路径，对于一次dfs，表征路径的数据结构的状态代表当前dfs所在的节点位置
        dfs(0,nums,visited,temp,nums.size());
        // 参数意义：dfs起点；待处理的结构；路径选择；路径和所在节点；dfs中止条件
        return result;
    }   
    void dfs(int level, vector<int>& nums, vector<bool>& visited,vector<int>& temp, int n){
        if(level == n){
            result.push_back(temp);
            return ;
        }

        for(int i = 0;i < n;i++){
            if(visited[i]) continue;
            temp.push_back(nums[i]);
            visited[i] = true;
            dfs(level+1,nums,visited,temp,n);
            temp.pop_back();
            visited[i] = false;

        }
    }
private:
    vector<vector<int> > result;
};


class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        if(nums.size() == 0)  return result;
        vector<bool> visited(nums.size(),false);
        vector<int> temp;
        dfs(nums,visited,temp,nums.size()); // 优化掉level参数，因为temp结构就足够用来表示当前所在节点

        return result;
    }   
    void dfs(vector<int>& nums, vector<bool>& visited,vector<int>& temp, int n){
        if(temp.size() == n){
            result.push_back(temp);
            return ;
        }
        // 当前节点选择依赖之前走过的路径，则使用表示路径的数据结构来作为参数
        for(int i = 0;i < n;i++){
            if(visited[i]) continue;
            temp.push_back(nums[i]);
            visited[i] = true;
            dfs(nums,visited,temp,n);
            temp.pop_back();
            visited[i] = false;
        }
    }
private:
    vector<vector<int> > result;
};

int main(){
    Solution s;
    vector<int> v = {1,2,3,4};
    auto p = s.permute(v);
    for(int i = 0;i < p.size();i++){
        for(int j = 0;j < p[0].size();j++){
            cout<<p[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}