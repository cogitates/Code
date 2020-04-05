// add two numbers
// https://leetcode.com/problems/add-two-numbers/
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(0); // 将dummy建立在栈上
        ListNode* tail = &dummy;  // 新链表的尾指针

        int sum = 0;
        // 任何一个数字没有处理完或者仍然有进位的情况下，循环继续
        while(l1 || l2 || sum){ // 有一个条件成立即可运行
            sum += (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;
            tail->next = new ListNode(sum % 10);
            sum /= 10;
            tail = tail->next;
        }
        return dummy.next;
    }
};