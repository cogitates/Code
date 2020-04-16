// Validate Binary Search Tree
// https://leetcode.com/problems/validate-binary-search-tree/

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
    bool isValidBST(TreeNode* root) {
        return isValidBST(root,LLONG_MIN,LLONG_MAX);
    }
private:
    bool isValidBST(TreeNode* root,long min_val,long max_val){
        if(!root) return true;
        if(root->val <= min_val || root->val >= max_val)
            return false;
        return isValidBST(root->left,min_val,root->val)
            && isValidBST(root->right,root->val,max_val);
    }
};

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isValidBST(root,nullptr,nullptr);
    }
private:
    // 如果以root为根的树是一个合法二叉树，那么isValidBST将会返回true
    bool isValidBST(TreeNode* root,int* min_val,int* max_val){
        if(!root) return true;
        if((min_val &&root->val <= *min_val)
         || (min_val && root->val >= *max_val))
            return false;
        return isValidBST(root->left,min_val,&root->val)
            && isValidBST(root->right,&root->val,max_val);
    }
};


class Solution {
public:
    bool isValidBST(TreeNode* root) {
        prev = nullptr;
        return inOrder(root);
    }
    
private:
    TreeNode* prev;
    bool inOrder(TreeNode* root){
        if(!root) return true;
        if(!inOrder(root->left)) // 左子树不成立
            return false;
        if(prev && root->val <= prev->val) // 根节点不大于所有左子树节点
            return false;
        prev = root; //更新prev为当前遍历的节点，树中每次递归都只是访问一个节点
        return inOrder(root->right);
    }
};