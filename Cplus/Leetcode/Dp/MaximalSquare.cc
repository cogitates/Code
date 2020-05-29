// Maximal Square
// https://leetcode.com/problems/maximal-square/

#include <bits/stdc++.h>
using namespace std;


// Brute Force
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.empty())  return 0;
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<vector<int>> sums(m+1, vector<int>(n+1,0));
        for(int i = 1;i <= m;i++){
            for(int j = 1;j <= n;j++){ // all from [0,0] ==> [m,n] square
                sum[i][j] = matrix[i-1][i-1] - '0'
                          + sums[i-1][j]
                          + sums[i][j-1]
                          + sums[i-1][j-1];
            }
        }

        int ans = 0;
        // for target square
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= n;j++){
                for(int k = min(m-i+1,n-j+1);k > 0;k--){
                    int sum = sum[i+k-1][j+k-1]
                            - sums[i+k-1][j-1]
                            - sums[i-1][j+k-1]
                            + sums[i-1][j-1];
                    if(sum == k*k){
                        ans = max(ans,sum);
                        break;
                    }
                }
            }
        }
        return ans;
    }
};


class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int> sizes(m, vector<int>(n,0));
        int ans = 0;
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                sizes[i][j] = matrix[i][j] - '0';
                if(!sizes[i][j]) continue;

                if(i == 0 || j == 0){
                    // do nothing
                }else if(i == 0)
                    sizes[i][j] = sizes[i][j-1] + 1;
                else if(j == 0)
                    sizes[i][j] = sizes[i-1][j] + 1;
                else 
                    sizes[i][j] = min(min(sizes[i-1][j-1],
                                          sizes[i-1][j]),
                                          sizes[i][j-1]) + 1;

                ans = max(ans, sizes[i][j] * sizes[i][j]);
            }
           
        }
         return ans;
    }
};