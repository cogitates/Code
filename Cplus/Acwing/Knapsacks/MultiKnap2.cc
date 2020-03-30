// 多重背包问题2 二进制优化方法，
// https://www.acwing.com/problem/content/5/
// https://www.zhihu.com/question/316416327 复制理解
#include <bits/stdc++.h>
using namespace std;

const int N = 2010;

int n,m;
int v[N],w[N];
// 对于多重背包问题，将n个物品拆开成n份，放入物品数组中，这样就将多重背包转化为01背包问题
// 使用1 2 4 8等数对物品进行拆分

// 注意，拆开n之后新组成的物品序列(1,2..[lgn])，可以模拟取任意(1-n)个物品的情况
int f[N];


struct Good{
    int v,w;
};

int main(){
    vector<Good> goods;  
    cin >> n >> m;
    for(int i = 0;i < n;i++){
        int v, w, s;
        cin >> v >> w >> s;
        for(int k = 1;k <= s;k *=  2){
            s -= k;
            goods.push_back({v*k, w*k});
        }
        if(s > 0) goods.push_back({v*s, w*s});
    }

    for(auto good : goods){
        for(int j = m;j >= good.v;j--){
            f[j] = max(f[j],f[j-good.v]+good.w);
        }
    }

    cout << f[m] << endl;
    return 0;
}