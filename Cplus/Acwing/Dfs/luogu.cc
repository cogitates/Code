#include <iostream>
#include <cstdio>
using namespace std;

int n;
int a[32][32], visited[32][32];
int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};

void dfs(int x, int y){
    if(x < 0 || x > n+1 || y < 0 || y > n+1 || visited[x][y] || a[x][y] == 1) return ;
    visited[x][y] = 1;
    a[x][y] = 0;
    for(int t = 0; t < 5;t++){
        dfs(x+dir[t][0],x+dir[t][1]);
    }
}

int main(){
    int i, j;
    scanf("%d",&n);
    for(int i = 1;i < n;i++){
        for(int j = 1;j <= n;j++){
            scanf("%d", &a[i][j]);
            if(!a[i][j])
                a[i][j] = 2;
        }
    }
    dfs(0,0);
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            printf("%d",a[i][j]);
        }
        printf("\n");
    }
    return 0;
}