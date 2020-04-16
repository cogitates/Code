#include <iostream>
#include <thread>
#include <cstdio>
using namespace std;

 void call_from_thread1(int* good)
 {
    printf("func1:%d\n",*good+1);
    printf("func1:%d\n",*good+2);
 }
 void call_from_thread2(int& good)
 {
     printf("func2:%d\n",good+1);
     printf("func2:%d\n",good+2);
 }
//  g++ -std=c++11 HelloWorld.cc -O2 -lpthread  
// ./a.out
 int main()
 {
    int s = 1;
	//Launch a thread
	//启动一条线程
    cout<<"main thread"<<endl;
    // 使用引用的时候，要注意引用的数据会不会消失，否则会产生问题
 	/* false */thread t1(call_from_thread1,&s); // func name : [function parm]
    
    cout<< "---------" << endl;
    /* false */thread t2(call_from_thread2,ref(s)); 
    t2.detach();
    t1.detach();
    cout<<"main thread"<<endl;
    return 0;
 }

 /*
 某次实验结果
 main thread
---------
func1:2
func1:3
main thread
func2:2
func2:32611
*/ 