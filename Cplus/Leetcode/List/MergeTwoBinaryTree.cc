// Merge Two Binary Trees
// https://leetcode.com/problems/merge-two-binary-trees/

#include <bits/stdc++.h>
using namespace std;
//  Definition for a binary tree node.
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(!t1 || !t2) return t1 ? t1 : t2;

        auto root = new TreeNode(t1->val + t2->val);
        root->left = mergeTrees(t1->left,t2->left);
        root->right = mergeTrees(t1->right,t2->right);
        return root;
    }
};

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(!t1 || !t2) return t1 ? t1 : t2;

        auto root = t1; // 直接使用已有节点
        root->val += t2->val;
        root->left = mergeTrees(t1->left,t2->left);
        root->right = mergeTrees(t1->right,t2->right);
        return root;
    }
};