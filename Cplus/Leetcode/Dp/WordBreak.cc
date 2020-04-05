// Word Break   
// https://leetcode.com/problems/word-break
#include <bits/stdc++.h>
using namespace std;
// 解决这个问题，一定要明白原子问题是什么
// 这个题目的原子问题就是substr操作
// 接下来就是考虑如何思考缩小问题规模
// 考虑使用什么数据结构，如何对给定参数进行状态转化
class Solution1 {
public:
    // O(N^3)
    bool wordBreak(string s, vector<string>& wordDict) {
        int size = s.size();
        // |0|1|2| next line i is |
        // dp[i] = s[0,i] can break = dp[k] && findStr(k,i-k);
        vector<bool> dp(size+1,false);
        // base case
        dp[0] = true; // 空字符串
        for(int i = 1;i <= size;i++){ // status
            for(int k = 0;k < i;k++){ // choice
                // cout<<i<<" "<<k<<endl;
                if(dp[k] && findStr(s.substr(k,i-k),wordDict)){
                    dp[i] = true;
                    break;
                }
            }
        }        
        return dp[size];
    }
private:
    bool findStr(string s,vector<string> wordDict){
        for(int i = 0;i < wordDict.size();i++){
            if(s == wordDict[i]){
                return true;
            }
        }
        return false;
    }
};


class Solution2 {
public:
    // O(N^2)
    bool wordBreak(string s, vector<string>& wordDict) {
        int size = s.size();
        int m = wordDict.size();
        // |0|1|2| next line i is |
        // dp[i] = s[0,i] can break = dp[k] && findStr(k,i-k);

        unordered_set<string> dict;
        for(int i = 0;i < m;i++){
            dict.insert(wordDict[i]);
        }
        vector<bool> dp(size+1,false);
        // base case
        dp[0] = true; // 空字符串
        for(int i = 1;i <= size;i++){ // status
            for(int k = 0;k < i;k++){ // choice
                cout<<i<<" "<<k<<endl;
                if(dp[k] && dict.find(s.substr(k,i-k)) != dict.end()){
                    dp[i] = true;
                    break;
                }
            }
        }        
        return dp[size];
    }
};



class Solution3 {
public:
    bool wordBreak(string s, vector<string>& wordDict){
        unordered_set<string> dict(wordDict.cbegin(),wordDict.cend());
        return wordBreak(s, dict);
    }
    bool wordBreak(const string& s,const unordered_set<string>& dict){
        if(mp.count(s)) return mp[s]; 
        
        if(dict.count(s)) return mp[s]=true; // 递归结束

        for(int i = 1;i <s.length();i++){ // 递归缩小问题规模
            const string left = s.substr(0,i);
            const string right = s.substr(i);
            if(dict.count(right) && wordBreak(left,dict)){ // 使用子问题递归
                return mp[s] = true;
            }
        }
        return mp[s] = false;
    }
private:
    unordered_map<string,bool> mp;
};

int main(){
    Solution1 s;
    
    string str = "leetcode";
    vector<string> wordDict = {"leet","code"};
    cout<<s.wordBreak(str, wordDict)<<endl;

    return 0;
}