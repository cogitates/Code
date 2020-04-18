// https://www.acwing.com/problem/content/description/284/ 
// 石子合并
#include<iostream>

using namespace std;

const int N=310;
// 区间dp
int s[N];  // 前缀和
int f[N][N]; 
int n;
// f[i,j]: 所有起点为i，终点为j的方案的最小值
// 状态划分：
// 按照最后一步的位置进行划分
// f[i,j] = min(f[i,j], f[i,k] + f[k+1,j]+s[i,j])
int main()
{
    cin >> n;
    for(int i=1;i<=n;i++) cin >> s[i] , s[i] += s[i-1];

    for(int len = 2 ;len <= n ; len++){
        for(int i = 1 ;i + len - 1 <= n ; i++){
            int l = i,r=i + len - 1;
            f[l][r]=1e8;
            for(int j = l;j < r ; j++){
                f[l][r]=min(f[l][r], f[l][j] + f[j+1][r] + s[r]-s[l-1]);
            }
        }
    }
    cout << f[1][n] << endl;
    return 0;
}
