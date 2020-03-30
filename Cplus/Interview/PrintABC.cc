// dfs讲解

#include <bits/stdc++.h>
using namespace std;

string res;

void dfs(vector<string>& s,int level,vector<bool> judge){
    //1. dfs截至条件
    if(level == s.size()){
        cout<<res<<endl;
    }

    // 2. 遍历候选节点
    for(int i = 0;i < s.size();i++){
        // 2.1 对候选节点进行筛选
        if(!judge[i]){
            // 刷新状态，为下一步dfs做铺垫
            judge[i] = true;
            int temp_len = res.size();
            res += s[i];
            dfs(s,level+1,judge);
            // 复原现场，因为dfs已经结束
            res = res.substr(0,temp_len);
            judge[i] = false;
        }
    }
}



int main(){
    vector<string> s = {"a","b","c","d","e"};
    vector<bool> judge(s.size(),false);
    int level = 0;
    dfs(s,level,judge);
    return 0;
}