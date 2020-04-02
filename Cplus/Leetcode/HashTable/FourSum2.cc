// 4SumII
// https://leetcode.com/problems/4sum-ii/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int,int> hash;
        int res{0};
        for(auto a : A) {
            for(auto b : B){
                hash[a+b] ++;
            }
        } // 初始化频率
        for(auto c : C){
            for(auto d : D){
                res += hash[-c-d];
            }
        } // 累加频率计算res
        return res;
    }
};