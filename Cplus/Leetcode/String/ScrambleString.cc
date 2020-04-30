// Scramble String
// https://leetcode.com/problems/scramble-string/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isScramble(string s1, string s2) {
        if(s1 == s2) 
            return true;
        if(s1.length() != s2.length())
            return false;
        string str1 = s1, str2 = s2;
        sort(str1.begin(), str1.end());
        sort(str2.begin(), str2.end());
        if (str1 != str2) return false;
        int len = s1.length();
        for(int k = 1;k < len;k++){
            if(isScramble(s1.substr(0,k),s2.substr(0,k))
                && isScramble(s1.substr(k),s2.substr(k)))
                return true;
            if(isScramble(s1.substr(0,k),s2.substr(len-k))
                && isScramble(s1.substr(k),s2.substr(0,len-k)))
                return true;
        }
        return false;
    }
};