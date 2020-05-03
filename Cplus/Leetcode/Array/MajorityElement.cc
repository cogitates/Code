// Majority Element
// https://leetcode.com/problems/majority-element/

#include <bits/stdc++.h>
using namespace std;

/*
数据规模                        0  -->  1  -->  2  -->  3  -->  ........  -->  n
特定规模下的解的依赖关系          s0  <- s1  <-  s3  <-  s3   <-    s...    <-  sn     
目标解与特定规模解的关系                      result = choose(s0.....sn)      
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int result = nums.front();
        int count = 0;

        for(const int num : nums){
            if(num == result) ++count;
            else{
                --count;
                if(count == 0){
                    count = 1;
                    result = num;
                }
            }
        }
        return result;
    }
};