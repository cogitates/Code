// 最长公共子序列
// https://www.acwing.com/problem/content/899/

#include <bits/stdc++.h>
using namespace std;

const int N = 1010;

int n,m;
char a[N],b[N]; // two strings

int f[N][N]; // base case f[i][0]  = 0,f[0][j] = 0

int main(){
    cin >> n >> m >> a+1 >> b+1;
    // f[i,j] = 0 if(i,j == 0)
    // f[i,j] = f[i-1,j-1] + 1 if(a[i] == b[j])
    // f[i,j] = max(f[i,j-1],f[i-1,j]) if(a[i] != b[j])
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            f[i][j] = max(f[i-1][j],f[i][j-1]);
            if(a[i] == b[j]) f[i][j] = max(f[i][j],f[i-1][j-1]+1);
        }
    }
    
    cout<<f[n][m] <<endl;
    return 0;
}
