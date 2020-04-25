// Counting Bits
// https://leetcode.com/problems/counting-bits/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> countBits(int num) {
    // 对数分类，数分为奇数和偶数
        vector<int> result;
        result.push_back(0);
        for(int i = 1;i <= num;++i){
            if(i&1){
                result.push_back(result[i-1] + 1);
            }else{
                result.push_back(result[i/2]);
            }
        }
        return result;
    }
};