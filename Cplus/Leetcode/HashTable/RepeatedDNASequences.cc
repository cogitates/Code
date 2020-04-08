// Repeated DNA Sequences
// https://leetcode.com/problems/repeated-dna-sequences/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string,int> mp;
        vector<string> res;
        for(int i = 0;i + 10 <= s.size() ;i++){ // s.size() ==> size_t ==> not use -
            string str = s.substr(i,10);
            if(++mp[str] == 2) res.push_back(str); // always do mp[str]+1
        }
        return res;
    }
};