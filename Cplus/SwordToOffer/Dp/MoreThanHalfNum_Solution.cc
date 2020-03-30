#include <bits/stdc++.h>
using namespace std;

class Solution{
public: 
    int MoreThanHalfNum_Solution(vector<int> number){
        if(number.size() == 0)
            return 0;
        int result = number[0];
        int times = 1;
        for(int i = 0;i < number.size();i++){
            if(times == 0){
                result = number[i];
                times++;
            }else if(result == number[i]){
                times++;
            }else
                times--;
        }
        times = 0;

        for(int i = 0;i < number.size();i++){
            if(number[i] == result) ++times;
        }

        return (times > number.size() / 2) ? result : 0;
    }
};