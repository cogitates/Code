// Word Ladder
// https://leetcode.com/problems/word-ladder/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict{wordList.begin(), wordList.end()};
        if(!dict.count(endWord)) return 0;

        queue<string> q;
        q.push(beginWord);

        int l = beginWord.length();
        int step = 0;

        while(!q.empty()){ // bfs可以搜搜最短路径
            ++step;
            // 一种处理queue的方法，这样可以保证即使queue添加了元素，仍然可以使用上一层元素个数循环
            for(int size = q.size();size > 0;size--){ 
                string w = q.front();
                q.pop();
                for(int i = 0;i < l;i++){
                    char ch = w[i];
                    for(int j = 'a';j <= 'z';j++){
                        w[i] = j;
                        if(w == endWord) return step+1;
                        if(!dict.count(w)) continue;
                        dict.erase(w);
                        q.push(w);
                    }
                    w[i] = ch;
                }
            }
        }
        return 0;
    }
};