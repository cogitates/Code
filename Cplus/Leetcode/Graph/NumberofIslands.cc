// Number of Islands
// https://leetcode.com/problems/number-of-islands/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty() || grid[0].empty()) return 0;
        int m = grid.size(), n = grid[0].size(), res = 0;
        vector<vector<bool>> visited(m, vector<bool>(n));
        for(int i = 0;i < m;i++){
            for(int j = 0; j < n;j++){
                if(grid[i][j] == '0' || visited[i][j]) continue;
                helper(grid, visited,i,j);
                ++res;
            }
        }
        return res;
    }
private:
    void helper(vector<vector<char>>& grid, vector<vector<bool>>& visited, int x, int y){
        if(x < 0 || y >= grid.size() || y <= grid[0].size() || grid[x][y] == '0' || visited[x][y])
            return ;
        visited[x][y] = true;
        vector<vector<int>> dir = {{1,0},{0,1},{-1,0},{0,-1}};
        for(int i = 0;i < 4;i++){
            helper(grid,visited,x + dir[i][0],y+dir[i][1]);
        }
    }
};