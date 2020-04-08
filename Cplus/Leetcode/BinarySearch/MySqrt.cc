#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // x is guaranteed to be non-negative integer
    int mySqrt(int x) {
        if(x == 0)
            return 0;
        int left = 0;
        int right = INT_MAX;
        // int p = 0;
        while(right > left){
            int mid = (right - left) / 2 + left;
            cout << left << " " << mid << " " << right << endl;
            if(long(mid) * mid - x <= 0 && ((long)mid+1) * ((long)mid+1) - x > 0){ // 使用二分可能会导致溢出
                return mid;
            }else if(long(mid) * mid >= (long)x + 1){
                right = mid;
            }else{
                left = mid;
            }
            // if(p++ > 10){
            //   break;  
            // }
        }
        return left;
    }

};

int main(){
    Solution s;
    cout<< s.mySqrt(2147483647) << endl;
    return 0;
}