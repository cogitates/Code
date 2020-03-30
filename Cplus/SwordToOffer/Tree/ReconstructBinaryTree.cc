#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL){}
};

class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        if(pre.size() == 0 || vin.size() == 0 ){
            return nullptr;
        }
        TreeNode* head = new TreeNode(pre[0]);

        vector<int> left_pre, left_vin;
        vector<int> right_pre,right_vin;

        int index = 0;
        int len = pre.size();

        for(int i = 0;i < len;i++){
            if(vin[i] == pre[0]){
                index = i;
                break;
            }
        }

        for(int i = 0;i < index;i++){
            left_pre.push_back(pre[i+1]);
            left_vin.push_back(vin[i]);
        }

        for(int i = index + 1;i < len;i++){
            right_pre.push_back(pre[i]);
            right_vin.push_back(vin[i]);
        }

        head->left = reConstructBinaryTree(left_pre,left_vin);
        head->right = reConstructBinaryTree(right_pre,right_vin);
        return head;
    }
};

void preOrder(TreeNode *head){
    if(head == nullptr){
        return ;
    }
    cout<<head->val<<" ";
    preOrder(head->left);
    preOrder(head->right);
}

void preOrder2(TreeNode *head){
    stack<TreeNode *> s;
    TreeNode *p = head;
    // 注意这里的p指针，它起到遍历作用，它到哪，就遍历到哪
    // 值得注意的
    while(p != nullptr || !s.empty()){ // 两个条件任意一个满足都要继续遍历
        while(p != nullptr){
            cout<<p->val<<" "; // 访问
            s.push(p); // 仍有用，用于指针退回，入栈
            p = p->left; // 访问左节点
        }
        if(!s.empty()){
            p = s.top(); // 上个while循环p已经没有指向对象，现在将其重新指向下个需要访问的节点
            p = p -> right; // 栈中节点都是需要访问右节点的
            s.pop(); // 访问完后，这个点就没用了
        }
    }
}

void levelOrder(TreeNode* head){
    if(head == nullptr){
        return ;
    }
    queue<TreeNode *> q;
    q.push(head);

    while(!q.empty()){
        TreeNode* temp = q.front();
        cout<<temp->val<<" ";
        q.pop();
        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
    }
}
int main(){
    vector<int> arr1 = {1,2,4,7,3,5,6,8};
    vector<int> arr2 = {4,7,2,1,5,3,8,6};

    // Solution
    Solution s;
    TreeNode* head = s.reConstructBinaryTree(arr1,arr2);
    // preOrder
    preOrder2(head);
    cout<<endl;
    preOrder(head);
    cout<<endl;
    levelOrder(head);
    return 0;

}