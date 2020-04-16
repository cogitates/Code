// Binary Tree Level Order Traversal
// https://leetcode.com/problems/binary-tree-level-order-traversal/

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        return BFS(root);      
    }
    vector<vector<int> > BFS(TreeNode* root){
        if(!root) return {};
        vector<vector<int> > ans;
        vector<TreeNode*> curr,next;
        curr.push_back(root);
        while(!curr.empty()){
            ans.push_back({}); // ans is a vector
            for(TreeNode* node : curr){ // 当有了for循环作为一把利刃，就可以把容器看作元素处理
                ans.back().push_back(node->val); // ans.back() can access the last element of ans
                if(node->left) next.push_back(node->left);
                if(node->right) next.push_back(node->right);
            }
            curr.swap(next); // swap next and curr
            next.clear();
        }
        return ans;
    }
};


class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int> > ans;
        dfs(root,0,ans);
    }

    void dfs(TreeNode* root,int depth,vector<vector<int> >& ans){
        if(root == nullptr) return;
        while(ans.size()<=depth) ans.push_back({}); // dynamic enlarge size of ans
        dfs(root->left,depth+1,ans); // dfs函数就像抛悠悠球
        dfs(root->right,depth+1,ans);
        ans[depth].push_back(root->val);
    }
};