// Balanced Binary Tree
// https://leetcode.com/problems/balanced-binary-tree/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    // O(nlogn)
    bool isBalanced(TreeNode* root) {
        if(!root) return true; // special case
        int left_height = height(root->left);
        int right_height = height(root->right);
        // 求高度的过程中可以直接判断子树是否平衡，这样就可以降低事件复杂度
        return (abs(left_height - right_height)<=1) && isBalanced(root->left) && isBalanced(root->right);
    }
private:
    int height(TreeNode* root){
        if(!root) return 0;
        return max(height(root->left),height(root->right)) + 1;
    }
};

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(!root)  return true;
        bool balanced = true;
        height(root,&balanced);
        return balanced;
    }
private:
    int height(TreeNode* root,bool* balanced){
        if(!root) return 0;
        int left_height = height(root->left,balanced);
        int right_height = height(root->right,balanced);
        if(abs(left_height-right_height)>1){
            *balanced = false;
            return -1;
        }
        return max(left_height,right_height) + 1;
    }
};