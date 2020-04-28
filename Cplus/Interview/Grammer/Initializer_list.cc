// Initializer_list in stl
// https://www.youtube.com/watch?v=4y8od_B7bzU&list=PL-X74YXt4LVYo_bk-jHMV5T3LHRYRbZoH&index=5

#include <bits/stdc++.h>
using namespace std;

void print(initializer_list<int> vals){
    for(auto p = vals.begin();p!=vals.end();++p){
        cout<<*p<<"\n";
    }
}

int main(){
    print({1,2,3,4,5,5,6});
    return 0;
}