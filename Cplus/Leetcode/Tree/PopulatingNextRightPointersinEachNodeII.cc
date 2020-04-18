// Populating Next Right Pointers in Each Node II
// https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/

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
/*
          2
       /     \
    4         3
   / \        / \
  0   7     9   1
 /   / \    *  / \
5  12  6      8   11
       /
     10
*/
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

// dummy是创建出来的一个新的结点，其目的是为了指向root结点的下一层的首结点的前一个，
// 具体是这么做到的呢，主要是靠cur指针，首先cur指向dummy，然后cur再连上root下一层的首结点，这样dummy也就连上了。
// 然后当root层遍历完了之后，root需要往下移动一层，这样dummy结点之后连接的位置就正好赋值给root
// 然后cur再指向dummy，dummy之后断开，这样又回到了初始状态，以此往复就可以都连上了。
class Solution {
public:
    Node* connect(Node* root) {
        Node* dummy = new Node(0,NULL,NULL,NULL);
        Node *cur = dummy, *head = root;
        
        while(root){
             // root上层，cur下层 dummy指向下层头节点
            
            if(root->left){
                cur->next = root->left; // now cur == dummy cur 的next指向了下层的头节点，所以dummy也指向下层头结点
                cur = cur->next;
            }
            if(root->right){
                cur->next = root->right;
                cur = cur->next;
            }
            // cout<<root->val<<endl;
            // cout<<(dummy->next?dummy->next->val:0)<<endl;
            // cout<<(cur?cur->val:0)<<endl;
            root = root->next;
            
            if(!root){
                cur = dummy;
                root = dummy->next;
                dummy->next = NULL;
            }
        }
        return head;
    }
};