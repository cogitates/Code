#include <bits/stdc++.h>
using namespace std;

struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};

class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        if(pNode == nullptr)
            return nullptr;

        if(pNode->right == nullptr){ // 若无右节点，则找 第一个 父子关系为左的 祖先节点的 父节点
            while(pNode && pNode->next && pNode->next->left == pNode){
                pNode = pNode->next;
            }
            return pNode->next;
        }else{ //存在右节点，则查找右子树最左节点
            pNode = pNode->right;
            while(pNode && pNode->left) pNode=pNode->left;
            return pNode;
        }  
    }
};
