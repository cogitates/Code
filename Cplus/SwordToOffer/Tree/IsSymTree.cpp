#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

class Solution {
public:
    bool isSymmetrical(TreeNode* pRoot)
    {
        if(pRoot == nullptr){
            return true; // 处理 level 1
        }
        bool res = isSymmetric(pRoot->left,pRoot->right);
        return res;
    }
    //         root   level 1
    //     left    right  level 2
    // left right left right   level 3
    bool isSymmetric(TreeNode* left,TreeNode* right){
        if(left == nullptr && right == nullptr){ // 处理level 2
            return true;
        }
        if(left == nullptr || right == nullptr){ // 处理level 2
            return false;
        }
        if(left->val != right->val) // 处理level 2
            return false;
        // 处理 level 3
        return isSymmetric(left->left,right->right) && isSymmetric(right->left,left->right);
    }
};