//  Diameter of Binary Tree
// https://leetcode.com/problems/diameter-of-binary-tree/

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
    int diameterOfBinaryTree(TreeNode* root) {
        maxDepth(root);
        return res;
    }
private:
    int maxDepth(TreeNode* root){
        if(!root) return 0;
        if(mp.count(root)) return mp[root];
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        res = max(res,left+right);
        mp[root] = max(left,right) + 1;
        return mp[root];
    }
    int res;
    unordered_map<TreeNode*,int> mp;
};