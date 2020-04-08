// Split Linked List in Parts
// https://leetcode.com/problems/split-linked-list-in-parts/
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
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        int len = 0;
        for(ListNode* head = root;head;head= head->next) ++len;
        vector<ListNode*> ans(k,nullptr);
        int l = len / k; // smaller length
        int r = len % k; // how much blocks need plus one

        ListNode* head = root;
        ListNode* prev = nullptr;
        for(int i = 0;i < k;++i,--r){ // k => which is the length of vector, not list
            ans[i] = head; // init current head as vector element
            for(int j = 0;j < l + (r > 0);++j){
                prev = head;
                head = head->next;
            }
            // now the prev pointer point the last node of current vector element
            if(prev) prev->next=nullptr; 
        }      
        return ans;
    }
};