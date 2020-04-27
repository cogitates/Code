// Climbing Stairs
// https://leetcode.com/problems/climbing-stairs/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        vector<int> f(n+1);
        f.push_back(1);
        f.push_back(2);
        for(int i = 2;i < n;i++){
            f[i] = f[i-1] + f[i-2];
        }

        return f[n-1];
    }
};


class Solution {
public:
    int climbStairs(int n) {
        int prev = 1;
        int curr = 2;
        for(int i = 3;i <= n;i++){
            int temp = curr;
            curr = prev + curr;
            prev = temp;
        }
        return curr;
    }
};