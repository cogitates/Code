// Reverse Linked List
// https://leetcode.com/problems/reverse-linked-list/

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
/*
没有想到，过了这么久，仍然是不能非常顺利的写出reverseList
1. 这个题目中，对递归要有更加深入的理解，递归是一个双程，被调用者先完成，调用者后完成
2. 做链表题要画图分析，那怎么分析，如何分析才不会错，一个状态一个图，不要在一个图上完成多个状态的分析
*/
    ListNode* reverseList(ListNode* head) {
        auto dummy = ListNode(-1);
        if(!head->next) return head;
        dummy.next = head;
        head = head->next;
        dummy.next->next = nullptr;
        // init_statue : 1->2->3->4->5->null
        // add dummy : -1->1->2->3->4->5->null(and move head point to 2)
        // while loop 0 : -1->1->null    2->3->4->5->null
        // while loop 1 : temp->1->null    -1->2->3->4->5->null(and move head point to 3)
        // while loop 2 : -1->2->1->null   3->4->5->null (simliar to loop 0)
        while(head){
            auto temp = dummy.next;
            dummy.next = head;
            head = head->next;
            dummy.next->next = temp;
        }

        return dummy.next;
    }
};


class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next)      
            return head;
        // 这个最大的误区在于，在递归函数完成之后，head->next后面的链表已经反转了
        // 递归是一个双程,B调用A,B先执行，然后A执行完，接着B执行完
        // B-------------------------->A
        // B<--------------------------A
        auto newHead = reverseList(head->next); 
        // 此时head依然指向head->next,head->next已经是后面反转链表的最后一个节点了
        head->next->next = head;
        head->next = nullptr;
        return newHead;
    }
};