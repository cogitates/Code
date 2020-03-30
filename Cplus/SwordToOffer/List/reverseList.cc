#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
       }
};

ListNode* reverseList(ListNode *head){
    ListNode *newHead = new ListNode(-1);

    while(head != nullptr){
        // a->next 是线 a是点
        ListNode *next = head -> next;
        head->next = newHead -> next; // 将newhead指向的内容给head来指
        newHead->next = head;
        head = next;
    }
}