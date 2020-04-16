// Best Time to Buy and Sell Stock
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        const int n = prices.size();
        if(n < 1) return 0;
        vector<int> min_prices(n);
        vector<int> max_profit(n);
        // 动态规划问题，从数学归纳法的角度考虑 --> 若问题的问题规模较小的时候可以解决，那么对于规模稍大的问题能否解决
        min_prices[0] = prices[0]; // [0..i] 最小价格
        max_profit[0] = 0; // init base case

        for(int i = 1;i < n;i++){
            min_prices[i] = min(min_prices[i-1],prices[i]);

            max_profit[i] = max(max_profit[i-1],prices[i]-min_prices[i-1]);
        }
        return max_profit[n-1];
    }
};

/*
    dp[day][times][flag] was the status table 
    day means the due day;times means the trade times;flag means whether have stock today
base case:
    dp[-1][k][0] = dp[i][0][0] = 0
    dp[-1][k][1] = d[i][0][1] = -infinity

State transition equation:
    dp[i][k][0] = max(dp[i-1][k][0],dp[i-1][k][1]+prices[i])
    dp[i][k][1] = max(dp[i-1][k][1],dp[i-1][k-1][0]-prices[i])
*/

class Solution {
public:
    int maxProfit(vector<int>& prices){
        const int n = prices.size();

        vector<vector<int> > dp(n,vector<int>(n));
        for(int i = 0;i < n;i++){
            dp[i][0] = i == 0 ? 0 : max(dp[i-1][0],dp[i-1][1]+prices[i]);
            dp[i][1] = i == 0 ? -prices[i] : max(dp[i-1][1],-prices[i]);
        }
        return dp[n-1][0];
    }
};