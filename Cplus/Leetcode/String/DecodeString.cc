// Decode String
// https://leetcode.com/problems/decode-string/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string decodeString(string s) {
        int i = 0;
        return decode(s,i);
    }
private:
    string decode(string s, int& i){
        string res = "";
        int n = s.size();
        while(i < n && s[i] != ']'){
            if(s[i] < '0' || s[i] > '9'){ // 非数字
                res += s[i++];
            } else{ // 数字
                int cnt = 0;
                while(s[i] >= '0' && s[i] <= '9'){ // 处理系数
                    cnt = cnt * 10 + s[i++] -'0';
                }
                ++i; //跳过'['
                string t = decode(s,i);
                ++i; // 跳过']'
                while(cnt-- > 0){
                    res += t;
                }
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    cout<<s.decodeString("3[a]2[bc]")<<endl;
    return 0;
}