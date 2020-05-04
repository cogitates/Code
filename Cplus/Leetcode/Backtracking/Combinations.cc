// Combinations
// https://leetcode.com/problems/combinations/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        if(k <= 0 || k > n) return result;
        
        vector<int> temp;
        dfs(1,result,temp,k,n);
        return result;
    }
/*
同志啊
下面这个函数调用中,vector<int> temp没有加引用的运行情况是这样的
a few seconds ago	Accepted	720 ms	164.7 MB	cpp
当函数调用中,vector<int>& temp时，运行情况是下面这样的
a few seconds ago	Accepted	88 ms	9.5 MB	cpp
只是一个符号的不同，就会有如此巨大的性能差异，必须要引起重视
*/
    void dfs(int level, vector<vector<int>>& result, vector<int> temp,int k,int n){
        if(temp.size() == k){
            result.push_back(temp);
            return ;
        }
        // 当前节点的后续选择依赖当前节点的高度，因此使用高度作为参数
        for(int i = level;i <= n;i++){
            temp.push_back(i);
            dfs(i+1,result,temp,k,n);
            temp.pop_back();
        }
    }
};

int main(){
    Solution s;
    auto p = s.combine(4,2);
    for(int i = 0;i < p.size();i++){
        for(int j = 0;j < p[0].size();j++){
            cout<<p[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}