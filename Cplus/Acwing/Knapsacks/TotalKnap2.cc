#include <bits/stdc++.h>
using namespace std;

const int N = 1010;

int n,m;
int v[N],w[N];

int f[N];

int main(){

    cin >> n >> m;

    for(int i = 1;i <= n;i++) cin >> v[i] >> w[i];


    for(int i = 1;i <= n;i++){
        // 这里之所以是正序，是因为依赖同层右侧的值，需要先将其算出
        for(int j = v[i];j <= m;j++){
            // f[i][j] = f[i-1][j];
            // if(j >= v[i])
            f[j] = max(f[j], f[j-v[i]] + w[i]);
        }
    }
    // f[i,j] = max(f[i-1,j],f[i-1,j-v[i]]+w[i],f[i-1,j-2v[i]]+2w[i],f[i-1,j-3v[i]]+3w[i]...)
    // f[i,j-v[i]] = max(f[i-1,j-v[i]]+w[i],f[i-1,j-2v[i]]+2w[i],f[i-1,j-3v[i]]+3w[i]...)
    // so that f[i,j] = max(f[i-1,j],f[i,j-v[i]])
    cout << f[m] << endl;
    return 0;
}