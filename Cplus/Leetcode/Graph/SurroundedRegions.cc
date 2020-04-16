// Surrounded Regions
//  https://leetcode.com/problems/surrounded-regions/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        const int m = board.size(); // row
        if(m == 0) return ;
        const int n = board[0].size(); // col


        function<void(int,int)> dfs = [&](int x,int y){
            if(x < 0 || x >= n || y < 0 || y >= m || board[y][x] != 'O') return ;
            board[y][x] = 'G';
            dfs(x-1, y);
            dfs(x+1, y);
            dfs(x, y-1);
            dfs(x, y+1);
        };

        for(int y = 0;y < m;++y)
            dfs(0,y),// first row
            dfs(n-1, y); // last row
        for(int x = 0;x < n;++x)
            dfs(x,0),// first row
            dfs(x, m-1); // last row
        // 此时，给定数据结构已经被调整为 G,0,X图，对其进行刷新即可
        map<char, char> v{{'G','O'},{'O','X'},{'X','X'}};
        for(int y = 0; y < m;++y){
            for(int x = 0;x < n;++x)
                board[y][x] = v[board[y][x]];
        }
    }
};