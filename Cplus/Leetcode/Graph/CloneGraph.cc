// Clone Graph
// https://leetcode.com/problems/clone-graph/

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

/* 要做这个题，首先要明白原图是怎么存储的->使用邻接链表*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node) return nullptr;
        // 使用mp映射，原图和clone图的节点对应关系
        unordered_map<Node*,Node*>  mp;
        queue<Node*> q;
        Node* clone = new Node(node->val);
        q.push(node);
        mp[node] = clone;
        while(!q.empty()){
            Node* s = q.front();q.pop();
            for(Node* nei : s->neighbors){
                if(!mp.count(nei)){
                    mp[nei] = new Node(nei->val);
                    q.push(nei);
                }
                mp[s]->neighbors.push_back(mp[nei]);
            }
        }
        return clone;
    }
};