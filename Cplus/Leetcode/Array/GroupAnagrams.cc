// Group Anagrams
// https://leetcode.com/problems/group-anagrams/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        for(int i = 0;i < strs.size();++i){
            string temp = sortString(strs[i]);
            if(!mp.count(temp)){
                mp[temp] = res.size();
                res.push_back({});
            }
            res[mp[temp]].push_back(strs[i]);
        }
        return res;

    }
private:
    unordered_map<string,int> mp;
    string sortString(string str){
        sort(str.begin(),str.end());
        return str;
    }
};