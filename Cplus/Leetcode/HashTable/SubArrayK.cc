// Subarray Sum Equals K
// https://leetcode.com/problems/subarray-sum-equals-k/
#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> hash;      
        hash[0]=1; // 一个元素都没有的前缀和
        int res{0}, s{0};// s is prefix_sum
        for(auto x : nums){
            s += x;
            res += hash[s-k]; // 前缀和存的是sum(0,n)，若要得到subSum(i,j) = sum(j) - sum(i-1)
            cout<<s<<endl;
            hash[s]++;
        }
        return res;
    }
};

int main(){
    // 测试unordered_map的性质,下面这样使用会将mp[2]初始化为0
    unordered_map<int,int> mp{{1,2},{2,3}}; // c++ 列表初始化语法，支持统一初始化
    int t = mp[2];
    for(auto x : mp){
        cout<<x.first<<" "<<x.second<<endl;
    }
    // 结果测试
    vector<int> nums = {1,2,2,1};
    Solution s;
    cout<<s.subarraySum(nums,2);
    return 0;
}