#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> temp;
        dfs(s,0,-1,temp);
        return result;
    }
private:
    string conn(vector<string> str){
        string result;
        for(int i = 0;i < str.size();i++){
            result = result + "." + str[i];
        }
        return result.substr(1);
    }
    vector<string> result;
    void dfs(string s,int level,int index,vector<string> temp){
        // 1. 截至条件

        if(level == 4 || index == s.size()-1){
            if(level == 4 && index == s.size()-1){
                // result.push_back(conn(temp));
                cout<<conn(temp)<<endl;
            }
            return ;
        }

        // 2. 遍历候选情况
        for(int i = 1;i < 4;i++){
            // 字符串元操作
            if(index+1 >= s.size()) 
                break;
            string x = s.substr(index+1,i);
            // 2.1 筛选
            if(atoi(x.c_str()) < 256 && (x == "0" || x[0] != '0')){
                temp.push_back(x);
                dfs(s,level+1,index+i,temp);
                temp.pop_back();
            }
        }
    }
};

int main(){
    Solution s;
    vector<string> result = s.restoreIpAddresses("1111");
    return 0;
}