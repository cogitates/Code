// N-Queens
// https://leetcode.com/problems/n-queens/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        solve.clear();
        // init the board 3*3(every point .)
        board = vector<string>(n, string(n,'.'));

        col = vector<int>(n, 0);
        diag1 = vector<int>(2*n-1,0);
        diag2 = vector<int>(2*n-1,0);

        nqueens(n,0);
        return solve;
    }
private:
    vector<string> board;
    vector<int> col;
    vector<int> diag1;
    vector<int> diag2;
    vector<vector<string> > solve;

    bool available(int x,int y, int n){
        return !col[x]
            && !diag1[x+y]
            && !diag2[x-y+n-1];
    }

    // if add (x,y), mark col[x],diag1[x+y],diag2[x-y+n-1]
    void updateBoard(int x, int y, int n, bool is_put){
        col[x] = is_put;
        diag1[x+y]=is_put;
        diag2[x-y+n-1]=is_put;
        board[y][x] = is_put ? 'Q' : '.';
    }

    // dfs 
    void nqueens(const int n, const int y){
        // 1. 循环中止
        if(y == n){
            solve.push_back(board);
            return ;
        }

        // 2. 遍历待选节点,尝试每个column
        for(int x = 0;x < n;++x){
            // 2.1 排除无用节点
            if(!available(x,y,n)) continue;
            updateBoard(x,y,n,true);
            nqueens(n,y+1);
            updateBoard(x,y,n,false);
        }
    }
};