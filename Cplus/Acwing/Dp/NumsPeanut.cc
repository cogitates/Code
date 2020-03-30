// 摘花生
// http://www.jeepxie.net/article/817772.html
#include <bits/stdc++.h>
using namespace std;

const int N = 110;

int n,m;
int w[N][N];
int f[N][N];

int main(){
    int t;
    cin >> t;

    while(t--){
        cin >> n >> m;

        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= m;j++){
                cin >> w[i][j];
            }
        }

        // 动态规划问题的计算顺序就是递归调用依赖DAG图的拓扑顺序
        // f[i,j] = max(f[i-1,j]+w[i,j],f[i,j-1]+w[i,j])
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= m;j++){
                f[i][j] = max(f[i-1][j],f[i][j-1]) + w[i][j];
            }
        }

        cout<< f[n][m] << endl;
    }
}