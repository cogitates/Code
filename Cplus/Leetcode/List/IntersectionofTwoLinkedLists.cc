// Intersection of Two Linked Lists
// https://leetcode.com/problems/intersection-of-two-linked-lists/

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* a = headA;
        ListNode* b = headB;
        while(a && b){
            a = a->next;
            b = b->next;
        }     
        ListNode* p = a ? a : b;
        b = p == a ? headA : headB;
        a = b == headA ? headB : headA;
        while(p){
            p = p->next;
            b = b->next;
        }
        while(a && b){
            if(a == b)
                return a;
            a = a->next;
            b = b->next;
        }
        return nullptr;
    }
};