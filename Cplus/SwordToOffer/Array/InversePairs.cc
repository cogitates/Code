#include <bits/stdc++.h>
using namespace std;

class Solution { // 太慢
public:
    int InversePairs(vector<int> data) {
        int result = 0;
        for(int i = data.size() - 1;i > 0;i--){ // 这里是data.size() - 1
            for(int j = 0;j < i;j++){
                if(data[j] > data[j+1]){
                    swap(data[j],data[j+1]);
                    result++;
                }
            }
        }
        return result % 1000000007;
    }

};

class Solution2{
public:
    int InversePairs(vector<int> data){
        // temp.capacity = data.size();
        mergeSort(data,0,data.size()-1);
        return result % 1000000007;
    }

    void mergeSort(vector<int> data, int start, int end){
        if(end <= start)
            return ;
        int m = start + (end - start) / 2;
        mergeSort(data, start, m);
        mergeSort(data,m+1,end);
        merge(data, start,m,end);
    }

    void merge(vector<int> data,int start,int mid,int end){
        int lo = start;
        int hi = mid + 1;

        for(int k = start;k <= end;k++){
            if(lo > mid) temp[k] = data[hi++];
            else if(hi > end) temp[k] = data[lo++];
            else if(data[lo] > data[hi]){
                data[k] = data[hi++];
                result++;
            }else   data[k] = data[lo++];
        }
    }
private:
    vector<int> temp;
    int result = 0;
};