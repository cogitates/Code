// Letter Combinations of a Phone Number
// https://leetcode.com/problems/letter-combinations-of-a-phone-number/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        vector<string> res;
        vector<string> dict{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        dfs(digits, dict, 0, "", res);
        return res;
    }
private:
    void dfs(string& digits, vector<string>& dict, int level, string out, vector<string>& res){
        if(level == digits.size()) {res.push_back(out);return;}
        string str = dict[digits[level] - '0']; // elem in dict
        for(int i = 0;i < str.size();i++){
            dfs(digits, dict, level+1, out+str[i],res);
        }
    }
};