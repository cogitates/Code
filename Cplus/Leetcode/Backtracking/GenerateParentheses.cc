// Generate Parentheses
// https://leetcode.com/submissions/detail/334794661/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string cur;
        if(n > 0) dfs(n,n,cur,ans);
        return ans;
    }
private:
    void dfs(int l, int r, string& cur,vector<string>& ans){
        if(l+r == 0){
            ans.push_back(cur);
            return ;
        }
        if(r < l) return ;
        if(l > 0){
            dfs(l-1,r,cur+= "(",ans);
            cur.pop_back();
        }
        
        if(r > 0){
            dfs(l,r-1,cur+=")",ans);
            cur.pop_back();
        }
    }
};