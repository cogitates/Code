#include <iostream>
#include <thread>
using namespace std;

class Test{
public:
    void operator () (){ // 所有重载()操作符的类都是函数化类
        cout<<"test1"<<endl;
        cout<<"test2"<<endl;
        cout<<"test3"<<endl;
    }
};
//  g++ -std=c++11 HelloWorld.cc -O2 -lpthread  
// ./a.out
 int main()
 {  
     Test test;
     thread t1{test};
     cout<<"main thread1"<<endl;
     cout<<"main thread2"<<endl;
     t1.join();
     return 0;
 }