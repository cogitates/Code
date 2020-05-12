// Combination Sum
// https://leetcode.com/problems/combination-sum/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> temp;
        int sum  = 0;
        sort(candidates.begin(),candidates.end());
        dfs(candidates,0,res,temp,sum,target);
        return res;
    }
private:
    void dfs(vector<int>& candidates,int cur,vector<vector<int>>& res, vector<int>& temp,int& sum,const int target){
        if(sum == target){
            res.push_back(temp);
            return ;
        }

        for(int i = cur;i < candidates.size();i++){
            if(target >= sum + candidates[i]){
                sum = sum + candidates[i];
                temp.push_back(candidates[i]);
                dfs(candidates,cur++,res,temp,sum,target);
                temp.pop_back();
                sum = sum - candidates[i];
            }else{
                return ;
            }
            
        }
    }  
};

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> temp;
        sort(candidates.begin(),candidates.end());
        dfs(candidates,0,res,temp,target);
        return res;
    }
private:
    void dfs(vector<int>& candidates,int cur,vector<vector<int>>& res, vector<int>& temp,int& target){
        if(target == 0){
            res.push_back(temp);
            return ;
        }

        for(int i = cur;i < candidates.size();i++){
            if(target >= candidates[i]){
                temp.push_back(candidates[i]);
                target=target-candidates[i];
                dfs(candidates,cur++,res,temp,target);
                target=target+candidates[i];
                temp.pop_back();
            }else{
                return ;
            }
            
        }
    }  
};