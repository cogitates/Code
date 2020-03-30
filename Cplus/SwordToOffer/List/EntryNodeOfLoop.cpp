#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
       }
};

class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        ListNode *fast = pHead;
        ListNode *slow = pHead;

        // path_fast = 2x  path_slow = x
        // fast - slow = n * R
        // slow = n * R;
        // when p = m tatal_slow = n * R + m 
        while(fast != nullptr && fast->next != nullptr){
            fast = fast -> next -> next;
            slow = slow -> next;
            if(slow == fast){
                ListNode *p = pHead;
                while(p != slow){
                    p = p -> next;
                    slow = slow -> next;
                }
                return p;
            }

        }
        return nullptr;
    }
};