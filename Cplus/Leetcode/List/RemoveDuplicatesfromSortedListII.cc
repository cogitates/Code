// Remove Duplicates from Sorted List II
// https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/

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
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        ListNode dummy(-1);
        dummy.next = head;

        ListNode* curr = &dummy;
        

        while(curr->next){
            ListNode* prev = curr->next;
            while(prev->next && prev->next->val == prev->val){
                prev = prev->next;
            }
            if(curr->next != prev){ // prev和curr之间的距离大于1
                curr->next = prev->next;
            }else{  // curr和prev之间的距离等于1
                curr = curr->next;
            }
        }
        return dummy.next;
    }
};
