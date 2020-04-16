// Best Time to Buy and Sell Stock II
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() <= 1) return 0;
        int sum = 0;
        for(int i = 1;i < prices.size();i++){
            if(prices[i] - prices[i-1] > 0)  sum += prices[i] - prices[i-1];
        }
        return sum;
    }
};