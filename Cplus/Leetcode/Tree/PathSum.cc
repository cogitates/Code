//  Path Sum
// https://leetcode.com/problems/path-sum/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution{
public:
    vector<vector<int> > pathSum(TreeNode* root, int sum){
        vector<vector<int> > ans;
        vector<int> curr;
        pathSum(root,sum, curr, ans);
        return ans;
    }
private:
    void pathSum(TreeNode* root, int sum, vector<int>& curr, vector<vector<int> >& ans){
        if(root == nullptr) return ;
        if(root->left==nullptr && root->right==nullptr){
            if(root->val == sum){
                ans.push_back(curr); // ans 维护结果，只有叶子节点满足条件才更新
                ans.back().push_back(root->val); // curr 维护当前遍历状态，任何一次递归都要更新，结束调用后恢复
            }
            return ;
        }
        curr.push_back(root->val);
        int new_sum = sum - root->val;
        pathSum(root->left,new_sum,curr,ans);
        pathSum(root->right,new_sum,curr,ans);
        curr.pop_back();
    }
}；