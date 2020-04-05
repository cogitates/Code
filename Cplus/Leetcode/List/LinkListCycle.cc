// Link List Cycle
// https://leetcode.com/problems/linked-list-cycle/

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
    // 快慢指针
    bool hasCycle(ListNode *head) {
        if(!head || !head->next)    return false;
        auto fast = head;
        auto slow = head;
        while(fast){
            if(!fast->next) return false;
            fast = fast->next->next;
            slow = slow->next;
            if(slow == fast) return true;
        }
        return false;
    }
};

class Solution {
public:
    // 使用unordered_set保存
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> visited;
        while(head){
            if(visited.count(head)) return true;
            visited.insert(head); // insert
            head = head->next;
        }
        return false;
    }
};