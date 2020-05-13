// Longest Substring Without Repeating Characters
// https://leetcode.com/problems/longest-substring-without-repeating-characters/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        const int n = s.size();
        int ans = 0;
        
        for(int i = 0;i < n;i++) { // 以i开头的字符子串，判断起最大长度
            vector<int> seen(128);
            int j = i;
            while(j < n && !seen[s[j]]){
                seen[s[j++]]++;
            }
            ans = max(ans,j-i);
        }
        return ans;
    }
};

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        const int n = s.length();
        int ans = 0;
        vector<int> idx(128,-1); // 构造一个虚拟头结点
        for(int i = 0,j = 0;j < n;++j){ // j负责移动==>左端点 i==>右端点
            i = max(i,idx[s[j]]+1); // 合法slide windows==>某个右端点对应的左端点
            ans = max(ans,j-i+1);
            idx[s[j]] = j;
        }
        return ans;
    }
};