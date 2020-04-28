// Daily Temperatures
// https://leetcode.com/problems/daily-temperatures/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
       int n = T.size();
       vector<int> res(n,0);
       stack<int> st;
       // 单调递减栈
       for(int i = 0;i < T.size();i++){
            //要入栈的节点不满足递减要求 while + push
            //要入栈的节点满足递减要求 push
            while(!st.empty() && T[i] > T[st.top()]) { 
                auto t = st.top();st.pop();
                res[t] = i - t;
            }
            st.push(i);
       }
       return res;
    }
};