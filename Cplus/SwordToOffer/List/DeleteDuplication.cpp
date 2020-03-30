#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
       }
};

class Solution1 {
public:
    // 1->2->3->3->4->4->5 => 1->2->3->4->5
    ListNode* deleteDuplication(ListNode* pHead)
    {
        if(pHead == nullptr || pHead->next == nullptr)
            return pHead;
        ListNode* p = pHead;      
        ListNode* temp;
        while(p != nullptr){
            if(p->next->val == p->val && p->next){
                temp = p->next;
                p->next = p->next->next;
                delete temp;
            }
            p = p->next;
        }
        return pHead;
    }
};

class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
        if(pHead == nullptr || pHead->next == nullptr)
            return pHead;
        
        ListNode *pre = new ListNode(0); // 创造头结点，便于标记边界
        pre->next = pHead;
        
        ListNode *head = pre;
        ListNode *cur = pHead;

        while(cur != nullptr){
            if(cur->next == nullptr) // 如果当前节点是最后一个节点，停止分析
                   break;
            // 在cur->next存在情况下，cur->val 和 cur->next->val只有两种关系
            if(cur->next && cur->val != cur->next->val){ 
                pre = cur;
                cur = cur -> next;
            }else{
                while(cur->next && cur->next->val == cur->val)
                    cur = cur->next;
                cur = cur ->next;
                pre->next = cur;
            }
        }
        return head->next;
    }
};