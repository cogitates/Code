// Trapping Rain Water
// https://leetcode.com/problems/trapping-rain-water/

#include <bits/stdc++.h>
using namespace std;


// Time Limit Exceeded
class Solution {
public:
    int trap(vector<int>& height) {
        const int n = height.size();
        int ans = 0;
        auto lo = height.cbegin();
        auto hi = height.cend();

        // [lo,hi]=[0,n]
        // [lo,lo+i+1] = [0,i+1] ==> max_element(0...i)
        // [lo+i,hi] = [i,n] ==> max_element(i...n-1)
        // 往左和往右算都包括i本身
        for(int i = 0;i < n;i++){
            int l = *max_element(lo,lo+i+1);
            int r = *max_element(lo+i,hi);
            ans += min(l,r) - height[i];
        }
        return ans;
    }
};


class Solution {
public:
    int trap(vector<int>& height) {
        const int n = height.size();
        vector<int> l(n);
        vector<int> r(n);
        int ans;
        // 因为上面多次重复计算左侧，右侧最大值，因此算法效率低下，
        // 这里我们使用动态规划思想来计算出某个范围的最大值
        for(int i = 0;i < n;++i){
            l[i] = i == 0 ? height[i] : max(l[i-1], height[i]);
        }
        for(int i = n-1;i >= 0;--i){
            r[i] = i == n-1 ? height[i] : max(r[i+1],height[i]);
        }
        for(int i = 0;i < n;++i){
            ans += min(l[i],r[i]) - height[i];
        }
        return ans;
    }
};


class Solution {
public:
    int trap(vector<int>& height) {
        const int n = height.size();
        if(n==0)  return 0;
        int l = 0;
        int r = n - 1;
        int max_l = height[l];
        int max_r = height[r];
        int ans = 0;
        // double pointer
        while(l < r){
            if(max_l < max_r){
                ans += max_l - height[l];
                max_l = max(max_l,height[++l]);
            }else{
                ans += max_r - height[r];
                max_r = max(max_r,height[--r]);
            }
        }
        return ans;
    }
};

int main(){
    int n = 10;
    vector<int> dp(n,0);
    // cend()指向容器最后一个元素的后一个
    cout<<*dp.cend()<<endl; //61809
    return 0;
    
}