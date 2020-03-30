#include <bits/stdc++.h>
using namespace std;

const int N = 6;

int n,m;
int v[N],w[N];

int f[N];

int main(){
    cin>>n>>m;
    // 输入
    /*
4 5
1 2
2 4
3 4
4 5
    */
    for(int i = 1;i <= n;i++) cin>>v[i]>>w[i];
    

    // 整体表现为下层依赖上层，右边依赖左边
    // 右面依赖左边比较难理解，注意，i层右面依赖i-1层的的左面
    for(int i = 1;i <= n;i++){
    // 这一条数组的状态{|第i层数据|第i-1层数据|} if从左往右刷新
    // 这一条数组的状态{|第i-1层数据|第i层数据|} if从右往左刷新
    // 如果从右往左刷新在本轮更新的值，不会影响本轮中其他未更新的值！较小的index对应的状态是上一轮的状态值！
        for(int j = m;j >= v[i];j--){
             f[j] = max(f[j],f[j-v[i]] + w[i]);
        }
    }
    cout<<f[m]<<endl;
}