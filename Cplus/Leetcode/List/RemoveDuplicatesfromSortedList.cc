// Remove Duplicates from Sorted List
// https://leetcode.com/problems/remove-duplicates-from-sorted-list/

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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* curr = head;
        ListNode* prev = head->next;
        while(prev){
            if(curr->val ==  prev->val){
                prev = prev->next;
                curr->next = prev;
                continue;
            }
            curr = curr->next;
            if(prev){
                prev = prev->next;
            }
        }
        return head;
    }
};