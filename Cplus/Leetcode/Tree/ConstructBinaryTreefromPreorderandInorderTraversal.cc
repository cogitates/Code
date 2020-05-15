// Construct Binary Tree from Preorder and Inorder Traversal
// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
private:
    TreeNode* buildTree(vector<int>& preorder,int pLeft, int pRight,vector<int>& inorder,int iLeft,int iRight){
        if(pLeft > pRight || iLeft > iRight) return nullptr;
        int i = 0;
        for(i = iLeft;i <= iRight;++i){
            if(preorder[pLeft] == inorder[i]) break;
        }
        TreeNode* cur = new TreeNode(preorder[pLeft]);
        cur->left = buildTree(preorder,pLeft+1,pLeft+i-iLeft,inorder,iLeft,i-1);
        cur->right = buildTree(preorder,pLeft+i-iLeft+1,pRight,inorder,i+1,iRight);
        return cur;
    }
};