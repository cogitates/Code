// Convert Binary Number in a Linked List to Integer
// https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/

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
    int getDecimalValue(ListNode* head) {
        int result = 0;
        while(head) {
            result = result<<1 + head->val;
            head = head->next;
        }
        return 0;
    }
};