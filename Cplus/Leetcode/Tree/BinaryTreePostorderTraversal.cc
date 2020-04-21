// Binary Tree Postorder Traversal
// https://leetcode.com/problems/binary-tree-postorder-traversal/

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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        postorderTraversal(root,ans);
        return ans;
    }
    
    void postorderTraversal(TreeNode* root,vector<int>& ans){
        if(!root) return;
        postorderTraversal(root->left,ans);
        postorderTraversal(root->right,ans);
        ans.push_back(root->val);
    }
};

/*
rev_postorder(root):
    if not root : return
    print(root->val)
    rev_postorder(root->right)
    rev_postorder(root->left)
postorder(root):
    reverse(rev_postorder(root))
*/
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if(!root) return {};
        deque<int> ans;
        stack<TreeNode*> s;
        s.push(root);
        
        while(!s.empty()){
            TreeNode* n = s.top();
            s.pop();
            ans.push_front(n->val); // O(1) deque是双向链表
            if(n->left) s.push(n->left);
            if(n->right) s.push(n->right);
        }
        
        return vector<int>(ans.begin(),ans.end());
    }
};

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        if(!root) return result;
        //遍历顺序是：root->left->root(1)->right->root(2)
        // 必须要分清楚返回到根节点时，是从左子树返回的，还是从右子树返回的，使用一个辅助bool变量用于标记状态
        stack<pair<TreeNode*,bool> > s;
        TreeNode* ptr = root;
        while(ptr || !s.empty()) { // when the (!ptr)and(s.empty()) while loop end
            if(ptr){ 
                s.push(make_pair(ptr,false)); 
                ptr = ptr->left;
            }else{
                auto now = s.top();s.pop();
                if(now.second == false){
                    s.push(make_pair(now.first,true));
                    ptr = now.first->right;
                }else{
                    result.push_back(now.first->val);
                }
            }
        }
        return result;
    }
};