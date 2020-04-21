// Binary Tree Preorder Traversal
// https://leetcode.com/problems/binary-tree-preorder-traversal/

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
    vector<int> preorderTraversal(TreeNode* root) {
        dfs(root);
        return result;
    }

private:
    vector<int> result;
    void dfs(TreeNode* root){
        if(root){
            result.push_back(root->val);
            dfs(root->left);
            dfs(root->right);
        }else{
            // do nothing
        }
    }
};


class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        if(root==nullptr) return result;
        stack<TreeNode*> s;
        TreeNode* ptr = root;
        while(ptr || !s.empty()) {
            if(ptr){
                result.push_back(ptr->val);
                s.push(ptr);
                ptr = ptr->left;
            }else{
                ptr = s.top();s.pop(); // 栈内的节点状态：已经访问，但是未处理右节点
                ptr = ptr->right;
            }
        }
        return result;
    }
};