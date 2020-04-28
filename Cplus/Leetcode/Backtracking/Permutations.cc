// Permutations
// https://leetcode.com/problems/permutations/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        if(nums.size() == 0)  return result;
        vector<bool> visited(nums.size(),false);
        vector<int> temp;
        dfs(0,nums,visited,temp,nums.size());

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