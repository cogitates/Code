// 多重背包问题1
// https://www.acwing.com/problem/content/4/
#include <bits/stdc++.h>
using namespace std;

const int N = 6;

int n,m;
int v[N],w[N];

int f[N];

/*
当要求恰好装满时
1. f[i] = 0
f[m] 为求的值
当不要求恰好装满
这里的负无穷可以理解为没有方案可以满足要求。
举个例子f[0,4]表示从前0个物品中挑选（没有物品可以选择）放入体积为4的背包，
如果要求恰好装满，智商只要>0都知道不可能放满，所以f[0,4]=-∞,那么同理可见f[0,1...n]都没有办法满足恰好放满的要求，它们的值都为-∞。
2. f[0] = 0 f[i] = -INF i != 0
*/

int main(){
    cin >> n >> m;
    for(int i = 0;i < n;i++){
        int v,w,s;
        cin >> v >> w >> s;
        for(int j = m;j >= 0;j--){
            for(int k = 1; k <= s && k*v <= j;k++){
                f[j] = max(f[j],f[j-k*v] + k*w);
            }
        }
    }

    cout<< f[m] << endl;
    return 0;
}