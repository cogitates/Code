// 二分查找
#include <bits/stdc++.h>
using namespace std;

int BinarySearch(vector<int>& arr,int target){
    int left = 0;
    int right = arr.size() - 1;
    while(left < right){
        int mid = (right - left) / 2 + left;
        if(arr[mid] == target)
            return mid;
        else if(arr[mid] > target)
            right = mid;
        else 
            left = mid + 1;
    }
    return -1;
}

int main(){
    vector<int> s = {1,3,4,4,32,34,65,433,2233};
    cout<<BinarySearch(s,32);
    cout<<endl;
    cout<<BinarySearch(s,44);
    return 0;
}