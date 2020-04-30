// Decode Ways
// https://leetcode.com/problems/decode-ways/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        if(s == "")  return 0;
        return helper(s,0,s.length()-1);
    }
private:
    int helper(const string& s, int l, int r){
        if(ways.count(l)) return ways[l];
        if(s[l] == '0') return 0;
        if(l >= r) return 1; // single digit

        // single code
        int w = helper(s,l+1,r);
        const int prefix = (s[l] - '0') * 10 + (s[l+1]-'0');
        // double code
        if(prefix <= 26)
            w += helper(s,l+2,r);
        ways[l] = w;
        return w;
    }
    unordered_map<int,int> ways;
};