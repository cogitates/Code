// Unique Binary Search Trees 
// https://leetcode.com/problems/unique-binary-search-trees
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numTrees(int n) {
        vector<int> f(n+1);
        //f[n] 表示n个节点的二叉树共有多少种
        f[0] = 1; 
        // f[n] = sum(f[k]*f[n-k-1]) when 0 <= k < n, and k -> vertex nums of left subtree
        for(int i = 1; i <= n;i++){ // 节点数
            f[i] = 0;
            for(int j = 0;j < i;j++){ // 
                f[i] += f[j] * f[i-j-1];
            }
        }
        return f[n];
    }
};