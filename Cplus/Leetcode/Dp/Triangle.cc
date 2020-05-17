// Triangle
// https://leetcode.com/problems/triangle/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> f(n+1, vector<int>(n+1,INT_MAX));

        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= i;j++){
                f[i][j] = triangle[i-1][j-1];
                if(i == 1 && j == 1)  continue;
                else if(j == 1) f[i][j] += f[i-1][j];
                else if(j == i) f[i][j] += f[i-1][j-1];
                else f[i][j] += min(f[i-1][j-1],f[i-1][j]);
            }
        }

        return *min_element(f[n].begin(),f[n].end());
    }
};