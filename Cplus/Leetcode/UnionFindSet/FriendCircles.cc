// Friend Circles
// https://leetcode.com/problems/friend-circles/

#include <bits/stdc++.h>
#include "UnionFind.h"
using namespace std;

class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int n = M.size();
        UnionFind uf(n);
        for(int i = 0;i < n;i++){
            for(int j = i + 1;j < n;j++){
                if(M[i][j] == 1) uf.Union(i,j);
            }
        }
        unordered_set<int> circles;
        for(int i = 0;i < n;i++){
            circles.insert(uf.Find(i));
        }
        return circles.size();
    }
};
