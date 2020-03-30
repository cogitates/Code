// 最低通行费用
// https://www.acwing.com/solution/acwing/content/5011/

#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int N  = 110; // 有限集数据规模
// 动态规划算法解决的是 **有限集中在给定约束条件下的最优化问题** 。
int cost[N][N];  // 给定约束
int f[N][N]; // 状态表示

int main(){

    int n ;
    cin >> n;

    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            cin >> cost[i][j];
        }
    }

    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            if(i == 1 && j == 1) f[i][j] = cost[i][j]; // 特判左上角
            else{
                f[i][j] = INF;
                if(i > 1) f[i][j] = min(f[i][j],f[i-1][j] + cost[i][j]); // 不在第一行
                if(j > 1) f[i][j] = min(f[i][j],f[i][j-1] + cost[i][j]); // 不在第一列
            }
        }
    }

    cout<< f[n][n] << endl;
    return 0;
}