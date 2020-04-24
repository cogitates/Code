#include <bits/stdc++.h>
using namespace std;

/*
这个const修饰函数只能再类中使用
void show() const{
    cout<<"show"<<endl;
}
*/

class TestConst{
public:
    void show(){
        cout<<"test"<<endl;
    }
    // const修饰的是类成员函数
    void show() const {
        cout<<"const test"<<endl;
    }
};

int main(){
    TestConst tc;
    tc.show();
    const TestConst tc2;
    tc2.show();
    return 0;
}