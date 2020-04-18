// 冒泡排序
#include <bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int> &arr){
    int n = arr.size();
    for(int i = n - 1;i > 0;i--){
        for(int j = 0;j < i;j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }

}

int main(){
    vector<int> s = {2,1,34,3,44,24,65,12,11,7,66};
    bubbleSort(s);
    for(int k : s){
        cout<<k<<" ";
    }
    return 0;
}