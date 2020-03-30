#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
       }
};

class Solution1 {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> result;
        if(head == nullptr)
            return result;
        ListNode *p = head;
        result.push_back(p->val);
        while(p->next){
            result.push_back(p->next->val);
        }      
        reverse(result.begin(),result.end());
        return result;
    }
};

class Solution2 {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        if(head != nullptr){ // head不能是空，否则head->next将是空引用
            printListFromTailToHead(head->next);
            result.push_back(head->val);
        }
        return result;
    }
private:
    vector<int> result;
};

