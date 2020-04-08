// Longest Palindromic Substring    
// https://leetcode.com/problems/longest-palindromic-substring
#include <bits/stdc++.h>
using namespace std;

class Solution1 {
public:
    string longestPalindrome(string s) {
        int len = s.size();
        string result = "";
        string temp;
        int result_len = 0; // keep the status you want
        int start = 0;
        for(int i = 0;i < len;i++){ 
            int l=i,r=i; // target string size is odd
            while(l >= 0 && r <= len-1 && s[l] == s[r]){
                    result_len=r-l+1;
                    start = l;
                    l--;
                    r++;
            }
            result = (s.substr(start,result_len).size() > result.size()) ? s.substr(start,result_len) : result;
        }

        for(int i = 0;i < len -1;i++){
            int l=i,r=i+1; // target string size is even
            while(l >= 0 && r <= len -1 && s[l] == s[r]){
                result_len = r-l+1;
                start = l;
                l--;
                r++;
            }
            result = s.substr(start,result_len).size() > result.size() ? s.substr(start,result_len) : result;
        }
        return result;
    } 
};

class Solution2 {
public:
    string longestPalindrome(string s) {
        int len = s.size();

        string result = "";
        string temp;
        for(int i = 0;i < len;i++){
            for(int j = 0;j <= i;j++){
                temp = s.substr(i,j-i+1);
                if(judge(temp) && temp.size() > result.size())
                    result = temp;
            }
        }
        return result;
    }
 
    bool judge(string s){
        int len = s.size();
        for(int i = 0;i < len / 2;i++){
            if(s[i] == s[len-1-i]){
                continue;
            }
            return false;
        }
        return true;
    }
};

int main(){
    Solution1 s;
    cout<<s.longestPalindrome("cbbd")<<endl;
    return 0;
}