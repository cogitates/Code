//  All O`one Data Structure
// https://leetcode.com/problems/all-oone-data-structure/

#include <bits/stdc++.h>
using namespace std;

class AllOne {
public:
    /** Initialize your data structure here. */
    AllOne() {
        
    }
    
    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        auto it = mp.find(key);
        // does not find key in hashmap
        if(it == mp.end()){
            if(ls.empty() || ls.front().value != 1)
                ls.push_front({1,{key}});
            else
                ls.front().keys.insert(key);
            mp[key] = ls.begin();
            return ;
        }

        // find key in hashmap
        auto ls_it = it->second;// list iterator
        auto n_it = next(ls_it);

        if(n_it == ls.end() || n_it->value != ls_it->value+1)
            n_it = ls.insert(n_it,{ls_it->value-1,{}});
        n_it->keys.insert(key);
        mp[key] = n_it;

        ls_it->keys.erase(key);
        if(ls_it->keys.empty())
            ls.erase(ls_it);
    }
    
    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        auto it = mp.find(key);
        if(it == mp.end()) return;

        auto ls_it = it->second;

        if(ls_it->value > 1){ // 如果value > 1，那么将之前移
            auto pr_it = prev(ls_it);
            if(ls_it == ls.begin() || pr_it->value != ls_it->value -1)
                pr_it = ls.insert(ls_it,{ls_it->value+1,{}});
            pr_it->keys.insert(key);
            mp[key] = pr_it;
        } else{ // 否则直接抹去
            mp.erase(key);
        }

        // 从list上抹去
        ls_it->keys.erase(key);
        if(ls_it->keys.empty())
            ls.erase(ls_it);
    }
    
    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        return ls.empty() ? "" : *ls.back().keys.cbegin();
    }
    
    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        return ls.empty() ? "" : *ls.front().keys.cbegin();
    }
private:
    struct Node{
        int value;
        unordered_set<string> keys;
    };
    list<Node> ls;
    unordered_map<string,list<Node>::iterator> mp;
};