//  Unique Paths
// https://leetcode.com/problems/unique-paths/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m < 0 || n < 0) 
            return 0;
        dp = vector<vector<int>>(n+1,vector<int>(m+1,0));
        for(int x = 1;x <= n;++x){
            for(int y = 1;y <= m;++y){
                if(x == 1 || y == 1) dp[x][y] = 1; // 如果不写这个条件，那么f[1][1]就会被覆盖
                else dp[x][y] = dp[x-1][y] + dp[x][y-1];
            }
        }
        return dp[n][m];
    }
private:
    vector<vector<int>> dp;
};

int main(){
    Solution s;
    cout<<s.uniquePaths(3,2)<<endl;
    return 0;
}