#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
       }
};

ListNode* mergeList(ListNode *head1,ListNode *head2){
    if(head1 == nullptr){
        return head2;
    }
    if(head2 == nullptr){
        return head1;
    }
    if(head1->val > head2->val){
        head2->next = mergeList(head1,head2->next);
        return head2;
    }else{
        head1->next = mergeList(head1->next,head2);
        return head1;
    }
}

ListNode* mergeList(ListNode* head1,ListNode* head2){
    ListNode* dummy = new ListNode(-1);

    ListNode* p1 = head1;
    ListNode* p2 = head2;
    // 如果节点为空能取val吗
    dummy->next = (p1->val > p2->val ? p2 : p1);

    while(p1 && p2){
        // 当取一个链表的值的时候，有没有考虑过判断这个链表是不是空的
        if(p1 -> val > p2->val){

        }
    }
}

ListNode* mergeList(ListNode* head1,ListNode* head2){
    ListNode* dummy = new ListNode(-1);
    ListNode* p = dummy;

    while(head1 && head2){ // when loop end
        int val1 = head1 == nullptr ? INT_MAX : head1->val;
        int val2 = head2 == nullptr ? INT_MAX : head2->val;

        if(val1 > val2){
            p->next = head2;
            head2 = head2->next;
        }else{
            p->next = head1;
            head1 = head1->next;
        }
        p = p->next;
    }

    return dummy->next;
}