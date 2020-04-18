#include <bits/stdc++.h>
using namespace std;

void heapify(vector<int> &arr, int start, int end);
void heapSort(vector<int> &arr){
    int size = arr.size();
    for(int i = size / 2;i >= 0;i--){ // 从最后一个父亲节点
        heapify(arr,i,size-1);
    }
    for(int i = size - 1;i >= 0;i--){
        swap(arr[0],arr[i]); // 最大数归位
        heapify(arr,0,i-1);  // 选出0 ~ (i-1)中最大的数，下次循环归位
    }
}

void heapify(vector<int> &arr, int start, int end){ // 以start开头的节点作为树根节点的建堆操作
    int dad = start;
    int son = dad * 2 + 1;
    while(son <= end){ // 子节点尚在范围中
        if(son + 1 <= end && arr[son] < arr[son+1]){
            son = son + 1;
        }
        if(arr[dad] > arr[son])
            return ;
        else {
            swap(arr[dad], arr[son]);
            dad = son;
            son = dad * 2 + 1;
        }
    }
}

int main(){
    vector<int> s = { 3, 5, 3, 0, 8, 6, 1, 5, 8, 6, 2, 4, 9, 4, 7, 0, 1, 8, 9, 7, 3, 1, 2, 5, 9, 7, 4, 0, 2, 6 };
    heapSort(s);
    for(int k : s)
        cout<<k<<" ";
    return 0;
}