// Unique Paths II
// https://leetcode.com/problems/unique-paths-ii/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if(m <= 0 || n <= 0)  return 0;
        if(obstacleGrid[0][0]) return 0;
        dp = vector<vector<long>>(m+1,vector<long>(n+1,0));
        dp[1][1]=1;
        for(int x = 1;x <= m;x++){
            for(int y = 1;y <= n;y++){
                // 三条分支
                /* case 1 */if(obstacleGrid[x-1][y-1]) dp[x][y] = 0; 
                /* case 2 */else if(x == 1 && y == 1) continue;
                /* case 3 */else dp[x][y] = dp[x-1][y] + dp[x][y-1];
            }
        }
        return dp[m][n];
    }

private:
    vector<vector<long>> dp;
};