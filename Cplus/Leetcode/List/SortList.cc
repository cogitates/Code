// Sort List
// https://leetcode.com/problems/sort-list/
#include <bits/stdc++.h>
using namespace std;

//Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

 class Solution {
public:
    ListNode* sortList(ListNode* head) {
        // 0 or 1 element
        if(!head || !head->next) return head;
        ListNode* slow = head;
        // ListNode* fast = head->next;
        // while(fast && fast->next){
        // 上下两种办法都是可以的,差这么一个位置，不影响循环的次数，而slow走的个数就是循环的次数
        // 上一种最后fast跑到lastNode->next
        // 下一种最后fast跑到lastNode
        ListNode* fast = head;
        while(fast->next && fast->next->next){
            fast = fast->next->next;
            slow = slow->next;
        }        
        ListNode* mid = slow->next;
        slow->next = nullptr;
        return merge(sortList(head),sortList(mid));
    }

    ListNode* merge(ListNode* l1, ListNode* l2){
        ListNode dummy(0);
        ListNode* tail = &dummy;
        while(l1 && l2){
            if(l1->val > l2->val) swap(l1,l2);
            tail->next = l1;
            l1 = l1->next;
            tail = tail->next;
        }

        tail->next = l1 ? l1 : l2;
        return dummy.next;
    }
};


class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;

        int len = 1;
        ListNode* cur = head;
        while(cur = cur->next) ++len;

        ListNode dummy(0);

        dummy.next = head;

        ListNode* l;
        ListNode* r;
        ListNode* tail;
        for(int n = 2; n < len;n <<= 1){
            cur = dummy.next;
            tail = &dummy;
            while(cur){
                //对于每一段要处理的链表，都应确保控制其链表头
                l = cur; // left part
                r = split(l,n); // right part
                cur = split(r,n);  // 迭代
                auto merged = merge(l,r); //merge left part and right part
                tail->next = merged.first;
                tail = merged.second;
            }
        }
        return dummy.next;
    }

private:
    ListNode* split(ListNode* head,int n){
        while(--n && head)
            head = head->next;
        ListNode* rest = head ? head->next : nullptr;
        if(head) head->next = nullptr;
        return rest;
    }

    pair<ListNode*, ListNode*> merge(ListNode* l1,ListNode* l2){
        ListNode dummy(0);
        ListNode* tail = &dummy;
        while(l1 && l2){
            if(l1->val > l2->val) swap(l1,l2);
            tail->next = l1;
            tail->next = l1;
            l1 = l1->next;
            tail = tail->next;
        }
        tail->next = l1 ? l1 : l2;
        while(tail->next) tail = tail->next;
        return {dummy.next,tail};
    }
};