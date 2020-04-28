// Variadic Template
// https://www.youtube.com/watch?v=TJIb9TGfDIw&list=PL-X74YXt4LVYo_bk-jHMV5T3LHRYRbZoH&index=2&t=166s

#include <bits/stdc++.h>
using namespace std;

void print(){
    // 递归调用终点，必须要有
}
template<typename T,typename... Types>
void print(const T& firstArg, const Types&... args){
    cout<<firstArg<<endl;
    cout<<sizeof...(args)<<endl;
    print(args...);
}

int main(){
    print(6.5, bitset<16>(344),43);
    cout<<__cplusplus<<endl; // cpp version 
    return 0;
}