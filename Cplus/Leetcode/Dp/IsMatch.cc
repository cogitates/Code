// Regular Expression Matching
// https://leetcode.com/problems/regular-expression-matching/
#include <bits/stdc++.h>
using namespace std;

class Solution1 {
public:
  bool isMatch(string s, string p) {
    return isMatch(s.c_str(), p.c_str());
  }
private:
  bool isMatch(const char* s, const char* p) {
    if (*p == '\0') return *s == '\0';
        
    // normal case, e.g. 'a.b','aaa', 'a'
    if (p[1] != '*' || p[1] == '\0') {
      // no char to match
      if (*s == '\0') return false;
 
      if (*s == *p || *p == '.')
        return isMatch(s + 1, p + 1);
      else
        return false;
    }
    else {
      int i = -1; // a* a出现0次
      while (i == -1 || s[i] == p[0] || p[0] == '.') { // a* 初次匹配/a*次数匹配/.*匹配
          if (isMatch(s + i + 1, p + 2)) return true; // 假定a*中a出现0次，模式后移2格
          if (s[++i] == '\0') break; // a*中a出现1-n次，这个时候字符串后移一格
      }
      return false;
    }
    return false;
  }
};

class Solution2 {
public:
    bool isMatch(string s, string p) {
        if(p.empty()) return s.empty();
        if(p.size() > 1 && p[1] == '*'){
            // p is not empty 
            // "a*" match "" || "a*" match "a"
            // pattern move 2 || string move 1
            return isMatch(s,p.substr(2)) || 
                        (!s.empty() && (s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1),p)) ;
        }else{
            // p and s both are not empty && first character match && other part match
            return !s.empty() && (s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1),p.substr(1));
        }
    }
};

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<bool> > dp(m+1,vector<bool>(n+1,false));

        // dp[i][j] = true means s[0,i) and p[0,j) matches
        dp[0][0] = true;

        // dp[i][j] = dp[i-1][j-1]   if(p[j-1] != '*' && (p[j-1] == s[i-1] || p[j-1] == '.'))
        // dp[i][j] = dp[i-1][j]  if(p[j-1] == '*' && (s[i-1] == p[j-2] || p[j-2] == '.') repeat at least one time)
        // dp[i][j] = dp[i][j-2] if(p[i-1] == '*' and repeat for 0 times)

        for(int i = 0;i <= m;i++){
            for(int j = 1;j <= n;j++){ // when j == 0 , (dp[i][j] = false if j > 0,already done)
                if(j > 1 && p[j-1] == '*'){
                    dp[i][j] = dp[i][j-2] || (i > 0 && dp[i-1][j] && (s[i-1] == p[j-2] || p[j-2] == '.'));
                }else{
                    dp[i][j] = i > 0 && dp[i-1][j-1]  && (s[i-1] == p[j-1] || p[j-1] == '.');
                }
            }
        }
        return dp[m][n];
    }
};


class  Solution{
private:
  vector<vector<int> > f;
  int m,n;
public:
  bool isMatch(string s, string p){
    n = s.size();
    m = p.size();

    f = vector(n+1,vector<int>(m+1,-1));
    // base case 是思维的切入点
    f[n][m] = 1; // 空串是相互匹配的

    return dp(0,0,s,p);
  }

  bool dp(int x,int y,string& s, string& p){
    if(f[x][y] != -1) return f[x][y];

    if(y == m){ // 如果模板串为空
      return f[x][y] = x == n; // 原串也必须为空才能匹配
    }

    bool first_match = x < n && (s[x] == p[y] || p[y] == '.');
    bool ans;

    if(y+1 < m && p[y+1] == '*'){
      // if(s[y] != p[x]){ 
      //   ans = dp(x,y+2,s,p);
      // }else{
      //   ans = first_match && dp(x+1,y,s,p);
      // }
      // 上面两种情况应该是只要有成立的即可，而不是非黑即白
      ans = dp(x,y+2,s,p) || (first_match && dp(x+1,y,s,p));
    }else{
      ans = first_match && dp(x+1,y+1,s,p);
    }
    return f[x][y] = ans;
  }
};
int main(){
    string s = "sb";
    string p = "a*sb";
    Solution so;
    cout<<so.isMatch(s,p)<<endl;
    return 0;
}
