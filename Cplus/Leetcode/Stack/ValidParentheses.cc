#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        unordered_map<char,char>  mp;
        mp[')'] = '(';
        mp['}'] = '{';
        mp[']'] = '[';
        if(n == 0) return true;
        stack<char> st;
        st.push(s[0]);
        for(int i = 1;i < s.size();++i){
            // stack.top() && unordered_map[key] 这两种操作都是有前提的--容器非空
            if(mp.count(s[i]) && !st.empty() && mp[s[i]] == st.top()){
                st.pop();
            }else{
                st.push(s[i]);
            }
        }
        return st.size() == 0;
    }
};

int main(){
    Solution s;
    cout<<s.isValid("[])");
    return 0;
}