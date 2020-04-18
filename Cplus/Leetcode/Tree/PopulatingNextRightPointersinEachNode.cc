// Populating Next Right Pointers in Each Node
// https://leetcode.com/problems/populating-next-right-pointers-in-each-node/

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        if(!root || !root->left) return root; // 递归结束的条件，节点为空或者为叶子节点
            root->left->next = root->right; // 处理root的两个子节点
        if(root->next) // 处理root的子节点和其兄弟节点的子节点的关系
            root->right->next = root->next->left;
        connect(root->left); // 递归处理左子树
        connect(root->right); // 递归处理右子树
        return root;
    }
};

class Solution{
public:
    Node* connect(Node* root){
        if(!root) return nullptr; 
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            for(int i = 0;i < size;i++){ // 层次遍历中for循环表示该层的节点数
                Node* t = q.front(); // 取队首元素
                q.pop(); // 弹出队首元素
                if(i < size - 1) // 除了最后一个节点，其他节点的next指针都要指向next节点
                    t->next = q.front();
                if(t->left) q.push(t->left); 
                if(t->right) q.push(t->right);   
            }
        }
        return root;
    }
};