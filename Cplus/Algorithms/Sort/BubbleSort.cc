// Bubble Sort

#include <bits/stdc++.h>
using namespace std;

template<typename T>
class BubbleSort{
public:
    void bubbleSort(vector<T>& arr){
        int n = arr.size();
        for(int i = 0;i < n;i++){
            for(int j = n-1;j > i;j--){
                if(arr[j] < arr[j-1]){
                    swap(arr[j],arr[j-1]);
                }
            }
        }
    }
};

int main(){
    BubbleSort<int> bs;
    vector<int> s = {1,32,23,12, 4, 4};
    bs.bubbleSort(s);
    for(int i = 0;i < s.size();i++){
        cout<<s[i]<<endl;
    }
    return 0;
}