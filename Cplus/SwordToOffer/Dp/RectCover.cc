#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rectCover(int number){
        if(number < 1) return 0;
        vector<int> s(number+1,0);
        return rectCover(number,s);
    }
    // 对于备忘录类型的问题，备忘录一是利用递归，而且要共享数组
    // 因此这个问题的参数才会是这个样子
    int rectCover(int number,vector<int> &s) {
        if(number == 1) return 1;
        if(number == 2) return 2;
        if(s[number] != 0)
            return s[number];
        else
        {
            s[number] = rectCover(number -1,s)  + rectCover(number - 2,s);
        }
        return s[number];
    }
};

