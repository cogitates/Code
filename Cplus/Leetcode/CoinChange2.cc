// Coin Change2
// https://leetcode.com/problems/coin-change-2/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        // dp[i][j] = sum(dp[i-1][j-k*coins[i-1]])      0<=k<=j/coins[i-1]
        // amount j with first i types of coins

        //with solve, amount in [0,amount]
        vector<vector<int> > dp(coins.size()+1,vector<int>(amount+1,0));

        //base case 
        dp[0][0] = 1;

        //Induction rule

        for(int i = 1;i <= coins.size();i++){
            for(int j = 0;j <= amount;j++){
                dp[i][j] = 0;
                for(int k = 0;k <= j / coins[i-1];k++){
                    dp[i][j] += dp[i-1][j-k*coins[i-1]];
                }
            }
        }
        int result = dp[coins.size()][amount];
        return result;
    }
};