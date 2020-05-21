// Best Time to Buy and Sell Stock with Cooldown
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
/*
 rest[i] = sell[i-1] 因为冷冻期   
 buy[i]  = max(sell[i-2] - price, buy[i-1]) 
 sell[i] = max(buy[i-1] + price, sell[i-1])
 并且 i只由i-1,i-2决定
*/ 
    int maxProfit(vector<int>& prices) {
        long long int buy = INT_MIN, pre_buy = 0, sell = 0, pre_sell = 0;
        for(int price : prices){
            pre_buy = buy;
            buy = max(pre_sell - price, pre_buy);
            pre_sell = sell;
            sell = max(pre_buy + price, pre_sell);
        }
        return sell;
    }
};