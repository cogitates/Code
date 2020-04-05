// merge K sorted Lists
// https://leetcode.com/problems/merge-k-sorted-lists/
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode dummy(0);
        ListNode *tail = &dummy;
        // 由于每个lambda对象都有一个匿名的类型，所以只能用auto来表达comp的类型
        // c++11 lambda表达式 ==> [捕获外部变量](形参列表)->返回值{函数体};
        auto comp = [](ListNode* a,ListNode* b){return a->val > b->val;};
        // auto 自动推断， decltype获取变量/对象类型
        // 想要正确初始化这个优先队列，还得在构造函数里再把lambda表达式本身传进去
        priority_queue<ListNode*,vector<ListNode*>, decltype(comp)> q(comp);

        for(ListNode* list : lists){
            if(list) q.push(list);
        }

        while(!q.empty()){
            tail->next = q.top();
            q.pop();
            tail = tail -> next;
            if(tail->next) q.push(tail->next);
        }// tail在多个链表上跳跃，并且改变链表间节点的指向关系

        return dummy.next;
    }
};


class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return merge(lists,0,lists.size()-1);
    }

private:
    ListNode* merge(vector<ListNode*>& lists,int l,int r){
        if(l > r) return nullptr;
        if(l == r) return lists[l];
        if(l+1 == r) return mergeTwoLists(lists[l],lists[r]);
        int m = l + (r - l) / 2;
        auto l1 = merge(lists,l,m);
        auto l2 = merge(lists,m+1,r);
        return mergeTwoLists(l1,l2);
    }

    ListNode* mergeTwoLists(ListNode* l1,ListNode* l2){
        ListNode dummy(0);
        ListNode* tail = &dummy;
        while(l1 && l2){
            if(l1->val > l2->val) swap(l1,l2); // 确保l1是头节点较小的链表
            tail->next = l1;
            l1 = l1->next;
            tail = tail->next;
        }
        tail->next = l1 ? l1 : l2;
        return dummy.next;
    }
};      