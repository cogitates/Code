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
    vector<vector<int> > Print(TreeNode* pRoot) {
        vector<vector<int> > result; // 处理特殊情况
        if(pRoot == nullptr){
            return result;
        } 
        queue<TreeNode *> q;
        vector<int> line;
        q.push(pRoot);
        int flag = 1; // 用于区分正反序
        while(!q.empty()){
            int lo = 0, hi = q.size();
            flag = 1 - flag;
            while(lo++ < hi){ // 使用值标记每一行的长度，队列进行对应操作
                TreeNode* temp = q.front();
                line.push_back(temp->val);
                q.pop();
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            if(flag == 1)
                 reverse(line.begin(),line.end()); // 反转序列
            result.push_back(line);
            line.clear(); // 及时清除序列
        }
        return result;
    }
};