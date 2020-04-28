// Low Bound
// https://blog.csdn.net/yang20141109/article/details/51934437

#include <bits/stdc++.h>
using namespace std;

// Binary Search
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

int LowBound(vector<int>& arr, int target){
    int left = 0;
    int right = arr.size() - 1;
    while(left < right){
        int mid = (right - left) / 2 + left;
        if(arr[mid] >= target){
            right = mid;
        }else{
            left = mid + 1; // 不等时，左边界动
        }
    }
    return left;
}

int UpperBound(vector<int>& arr, int target){
    int left = 0;
    int right = arr.size() - 1;
    while(left < right){
        int mid = (right - left) / 2 + left;
        if(arr[mid] <= target){
            left = mid + 1; // 相等时，左边界动
        }else{
            right = mid;
        }
    }
    return left;
}

int main(){
    vector<int> s = {1,3,4,4,23,23,23,32,34,65,433,2233};
    cout<<BinarySearch(s,23);
    cout<<endl;
    cout<<LowBound(s,23)<<" "<<*lower_bound(s.begin(),s.end(),23);
    cout<<endl;
    cout<<UpperBound(s,23)<<" " <<*upper_bound(s.begin(),s.end(),23);
    cout<<endl;
    return 0;
}