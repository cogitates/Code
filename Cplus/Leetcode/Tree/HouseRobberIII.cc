// House Robber III
// https://leetcode.com/problems/house-robber-iii/

#include <bits/stdc++.h>
using namespace std;


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };


class Solution {
public:
    int rob(TreeNode* root) {
        return dfs(root);
    }
private:
    unordered_map<TreeNode*, int> m;
    int dfs(TreeNode* root){
        if(!root) return 0;
        if(m.count(root)) return m[root];
        int res = 0;
        if(root->left){
            res += dfs(root->left->left) + dfs(root->left->right);
        }
        if(root->right){
            res += dfs(root->right->left) + dfs(root->right->left);
        }
        
        res = max(res + root->val, dfs(root->left) + dfs(root->right));
        m[root] = res;
        return res;
    }
};