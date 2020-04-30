// Min Stack
// https://leetcode.com/problems/min-stack/

#include <bits/stdc++.h>
using namespace std;

class MinStack {
private:
    stack<int> s1; // 正常栈
    stack<int> s2; // 最小值栈
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        s1.push(x);
        if(s2.empty()){
            s2.push(x);
        }else{
            int min = s2.top();
            if(min > x){
                s2.push(x);
            }else{
                s2.push(min);
            }
        }
    }
    
    void pop() {
        s1.pop();
        s2.pop();
    }
    
    int top() {
        return s1.top();
    }
    
    int getMin() {
        return s2.top();      
    }
};


// single stack
class MinStack {
private:
    int min_val;
    stack<int> s;
public:
    /** initialize your data structure here. */
    MinStack() {
        min_val = INT_MAX;
    }
    
    void push(int x) {
        // 1. 新元素最小 ==> 旧最小入栈,新元素入栈
        if(x <= min_val){
            s.push(min_val);
            min_val = x;
        }
        // 2. 新元素非最小 ==> 直接入栈
        s.push(x);
    }
    
    void pop() {
        int t = s.top();s.pop();        
        if(t == min_val){ //若栈顶是最小值，则栈顶后面是除栈顶外的最小值
            min_val = s.top(); s.pop();    
        }
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return min_val;
    }
};