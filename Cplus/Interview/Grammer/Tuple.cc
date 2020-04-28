// Tuple in C++
// https://www.cnblogs.com/huangfuyuan/p/9238598.html

#include <bits/stdc++.h>
using namespace std;

int main(){
    tuple<int,int,double> tp1;
    tp1=make_tuple(10,433,20.2);
    tuple<vector<int>,string> tp2;
    vector<int> v {1,2,3};
    string s {"good"};
    tie(v,s) = tp2;

    cout<<get<0>(tp1)<<endl;
    cout<<get<1>(tp2)<<endl;

    auto tp3 = tuple_cat(tp1,tp2);
    cout<<get<4>(tp3)<<endl;
    return 0;
}