// 

#include <bits/stdc++.h>
using namespace std;

int find(int amount,vector<int> coins){
    if(amount == 0) return 0;
    if(amount < 0) return -1;


    vector<int> dp(amount+1, amount+1);
    int result = INT_MAX;
    dp[0] = 0; // 状态的base case
    for(int i = 0;i < dp.size();i++){ // 遍历状态
        for(int coin : coins){ // 遍历选择，通过选择改变状态
            if(i - coin < 0) continue;
            dp[i] = min(dp[i], 1 + dp[i-coin]);
        }// 生成值
    }

    return dp[amount] == amount + 1 ? -1 : dp[amount];
}
