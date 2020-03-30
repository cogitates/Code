//  Burst Balloons
// https://leetcode.com/problems/burst-balloons/
#include <bits/stdc++.h>
using namespace std;


class Solution {
    vector<vector<int> > f;
    vector<int> nums;
public:
    int maxCoins(vector<int>& _nums) {
        int n = _nums.size();
        f = vector(n+2,vector<int>(n+2,-1));
        nums = vector<int>(n+2);
        nums[0] = 1;nums[n+1] = 1;

        for(int i = 0;i < _nums.size();i++){
            nums[i+1] = _nums[i];
        }
        help();
        // 当你看到一个离散问题的时候，有没有考虑如何缩小问题范围
        return dp(0,n+1);
    }

    void help(){
        for(int i = 0;i < f.size();i++){
            for(int j = 0;j < f[0].size();j++){
                cout<<f[i][j]<<" ";
            }
            cout<<endl;
        }
    }

    int dp(int x,int y){
        if(f[x][y] != -1) return f[x][y];
        // base case
        f[x][y] = 0;
        // 当你确定一个问题可以通过缩小问题规模解决的时候，有没有想到如何进行状态转移
        for(int i = x + 1;i < y;i++){
            f[x][y] = max(f[x][y], dp(x,i) + dp(i,y) + nums[x]*nums[y]*nums[i]);
        }
        return f[x][y];
    }
};


class Solution {
    vector<vector<int> > f;
    vector<int> nums;
public:
    int maxCoins(vector<int>& _nums) {
        int n = _nums.size();
        f = vector(n+2,vector<int>(n+2,0));
        nums = vector<int>(n+2);
        nums[0] = 1;nums[n+1] = 1;

        for(int i = 0;i < _nums.size();i++){
            nums[i+1] = _nums[i];
        }
        // 当你看到一个离散问题的时候，有没有考虑如何缩小问题范围
        
        for(int i = n;i >= 0;i--){
            for(int j = i+1;j < n+2;j++){
                for(int k = i+1;k < j;k++){
                    f[i][j] = max(f[i][j],f[i][k]+f[k][j] + nums[i]*nums[k]*nums[j]);
                }
            }
        }
        help();
        return f[0][n+1];
    }
    void help(){
        for(int i = 0;i < f.size();i++){
            for(int j = 0;j < f[0].size();j++){
                cout<<f[i][j]<<" ";
            }
            cout<<endl;
        }
    }
};