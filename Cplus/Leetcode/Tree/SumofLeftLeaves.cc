// Sum of Left Leaves
// https://leetcode.com/problems/sum-of-left-leaves/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*
这里是求所有的叶子节点
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root)  return 0;
        if(!root->left && !root->right) return root->val;
        if(!root->left) return sumOfLeftLeaves(root->right);
        if(!root->right) return sumOfLeftLeaves(root->left);
        return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
    }
};
*/

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root)  return 0;
        int temp = 0;
        if(root->left && !root->left->left && !root->left->right){
            temp = root->left->val;
        }
        return sumOfLeftLeaves(root->right) + sumOfLeftLeaves(root->left) + temp;
    }
};