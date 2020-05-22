#include <bits/stdc++.h>
using namespace std;

typedef struct {
    int a[2];
    double d;
}struct_t;

double fun(int i){
    volatile struct_t s;
    s.d = 3.14;
    s.a[i] = 1077741824;
    return s.d;
}


/*
    d7..d4 --> a[3]
    d3..d0 --> a[2]
    a[1]
    a[0]
    这个程序提醒我们要对c程序做边界检查
*/

int main(){
    cout<<fun(0)<<endl;
    cout<<fun(3)<<endl;
    return 0;
}