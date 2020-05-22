//  UTF-8 Validation
// https://leetcode.com/problems/utf-8-validation/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int left = 0;
        for(int& d : data){
            if(left == 0){ // 判断是第一个，各种情况都尝试一下
                if((d >> 3) == 0b11110) left = 3;
                else if((d >> 4) == 0b1110)  left = 2;
                else if((d >> 5) == 0b110)  left = 1;
                else if((d >> 7) == 0b0)  left = 0;
                else return false;
            }else{ // 判断是非第一个，右移六位
                if((d >> 6) != 0b10) return false;
                -- left;
            }
        }
        return left == 0;
    }
};

int main(){
    vector<int> data = {197,130,1};
    Solution s;
    cout<<s.validUtf8(data)<<endl;
    return 0;
}