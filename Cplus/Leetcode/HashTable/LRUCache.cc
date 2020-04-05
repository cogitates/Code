// https://leetcode.com/problems/lru-cache/
// LRU cache
#include <bits/stdc++.h>
using namespace std;
// hashmap + list


/*
C++11中，针对顺序容器(如vector、deque、list)，新标准引入了三个新成员：emplace_front、emplace和emplace_back，这些操作构造而不是拷贝元素。
这些操作分别对应push_front、insert和push_back，允许我们将元素放置在容器头部、一个指定位置之前或容器尾部。
*/

class LRUCache {
private:
    int capacity;
    list<pair<int,int> > cache;
    unordered_map<int,list<pair<int,int> >::iterator> mp;
public:
    LRUCache(int _capacity) {
        capacity = _capacity;
    }
    
    int get(int key) {
        const auto it  = mp.find(key);
        // if key does not exist
        if(it == mp.cend()) return -1;
        // move this key to the front of the list
        // c1.splice(c1.beg,c2,c2.beg,c2.end)
        // 将c2的[beg,end)位置的元素连接到c1的beg位置并且释放c2的[beg,end)位置的元素
        cache.splice(cache.begin(),cache,it->second); 
        return it->second->second;
    }
    
    void put(int key, int value) { 
        const auto it = mp.find(key);

        // key already exist
        if(it != mp.cend())   {
            it->second->second = value;
            cache.splice(cache.begin(),cache,it->second);
            return;
        }
        // key do not exist
        if(cache.size() == capacity){
            const auto& node = cache.back();
            mp.erase(node.first);
            cache.pop_back();
        }

        cache.emplace_front(key,value);
        mp[key] = cache.begin();
    }
};
