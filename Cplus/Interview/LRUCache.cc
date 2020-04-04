#include <bits/stdc++.h>
using namespace std;


class LRUCache {
    struct Cache{
        int key;
        int val;
        int mark = 0;
    };
    Cache* cache;
public:
    LRUCache(int capacity) {
        cache = (Cache*)malloc(sizeof(Cache) * capacity);
    }
    
    int get(int key) {
        
    }
    
    void put(int key, int value) { 
        
    }
};


int main(){

    return 0;
}