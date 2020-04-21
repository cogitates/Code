// Binary Tree Inorder Traversal
// https://leetcode.com/problems/binary-tree-inorder-traversal/

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
    vector<int> inorderTraversal(TreeNode* root) {
        dfs(root);
        return result;
    }
private:
    vector<int> result;
    void dfs(TreeNode* root){
        if(root){
            dfs(root->left);
            result.push_back(root->val);
            dfs(root->right);
        }
    }
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        if(!root)  return result;
        stack<TreeNode*> s;
        TreeNode* ptr;
        s.push(ptr);
        while(!s.empty() || ptr){   
            if(ptr->left){
                ptr = ptr->left;
            }else{
                result.push_back(ptr->val);
                s.push(ptr);
                ptr=ptr->right;
            }
        }
        return result;
    }
};