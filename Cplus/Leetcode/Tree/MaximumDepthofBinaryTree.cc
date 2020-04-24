// Maximum Depth of Binary Tree
// https://leetcode.com/problems/maximum-depth-of-binary-tree/

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
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        return std::max(maxDepth(root->left),maxDepth(root->right)) + 1;
    }
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        int depth = 0;
        dfs(root,depth);
        return result;
    }
    
    void dfs(TreeNode* root,int depth){
        if(!root){
            if(depth > result){
                result = depth;
            }
            return ;
        }
        dfs(root->left,depth+1);
        dfs(root->right,depth+1);
    }
private:
    int result = 0;
};


class Solution {
public:
    int maxDepth(TreeNode* root) {
        int depth = 0;
        if(!root) return depth;
        queue<TreeNode*> q{{root}}; // c++11统一初始化
        int right = 0,hi=1;
        TreeNode* temp;
        while(!q.empty()){
        // 这里曾经错过，最开始的right的值等于1，但是自己却初始化成了0
            right = hi,hi = 0;
            depth+=1;
            for(int i = 0;i < right;i++){
                temp = q.front();q.pop();
                if(temp->left) // 入队之前判断是否为空
                    q.push(temp->left), hi++;  // hi应该依附于每一个节点，而不是写在if外面
                if(temp->right)
                    q.push(temp->right), hi++;
            }
        }
        return depth;
    }
};