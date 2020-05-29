// quick sort
// https://algs4.cs.princeton.edu/23quicksort/Quick.java.html
#include <bits/stdc++.h>
using namespace std;

template<typename T>
class QuickSort{
private:
    int partition(vector<T>& res, int left, int right){
        T i = left;
        T j = right+1;
        T v = res[i];
        while(true){
            while(res[++i] < v){
                if(i == right) break;
            }

            while(v < res[--j]){
                if(j == left) break;
            }
            if(i >= j)  break;
            swap(res[i], res[j]);
        }
        cout<<" "<<(i == j)<<endl;
        swap(res[left], res[j]);
        return j;
    }

    void quickSort(vector<T>& res, int left, int right){
        if(left < right){
            int j = partition(res,left,right);
            quickSort(res, left, j-1);
            quickSort(res, j+1, right);
        }
    }
public:
    void quickSort(vector<T>& res){
        quickSort(res, 0, res.size()-1);
    }
};



int main(){
    vector<int> s = {1,32,23,12, 4, 4};
    QuickSort<int> qs;
    qs.quickSort(s);
    for(int i = 0;i < s.size(); i++){
        cout<<s[i]<<endl;
    }
    return 0;
}