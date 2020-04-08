// Linked List Components
// https://leetcode.com/problems/linked-list-components/
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
    int numComponents(ListNode* head, vector<int>& G) {
        unordered_set<int> f(G.begin(),G.end());
        unordered_map<int,vector<int> > g;
        int u = head->val; // 将链表的有向变为图的无向
        while(head->next){  // 因为成对处理一前一后两个节点，所以用后节点地为空作为循环结束地条件
            head = head->next; 
            int v = head->val;
            if(f.count(v) && f.count(u)){
                g[u].push_back(v);
                g[v].push_back(u);
            }
            u = v;
        }

        int ans = 0;
        unordered_set<int> visited;
        for(int u : G){
            if(visited.count(u)) continue;
            ++ ans;
            dfs(u,g,visited);
        }
        return ans;
    }

private:
    // dfs函数本质上只处理一个节点，就是cur节点，对于cur节点地不同，选择不同操作
    void dfs(int cur,unordered_map<int,vector<int> >& g,unordered_set<int>& visited){
        if(visited.count(cur)) return ;  // cur already in visited
        visited.insert(cur);  // cur not in visited
        for(const int next : g[cur]){
            dfs(next,g,visited);
        }
    }
};

class Solution {
public:
    int numComponents(ListNode* head, vector<int>& G) {
        unordered_set<int> g(G.begin(),G.end());
        int ans = 0;
        while(head){
            // change the list 0->1->2->3[0,1,3] ==> 1->1->0->1->null
            if(g.count(head->val) && (!head->next || !g.count(head->next->val))) // when meet 1->0 and 1->null, plus one
                ++ans;
            head = head->next;
        }
        return ans;
    }
};