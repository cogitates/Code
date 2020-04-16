#include <iostream>
#include <thread>
using namespace std;

 void call_from_thread()
 {
 	cout << "hello world!" << endl;
	cout << "whoami" << endl;
	cout << "abash" << endl;
 }
//  g++ -std=c++11 HelloWorld.cc -O2 -lpthread  
// ./a.out
 int main()
 {
	 //Launch a thread
	 //启动一条线程
 	thread t1(call_from_thread);
     cout<<"main thread"<<endl;
    // detach()后，与主线程关联的thread对象就会与主线程失去关联
    // 子线程将会驻留后台，结束后由运行时库辅助清理该线程相关资源
    cout<<t1.joinable()<<endl; // joinable() 判断线程是否可以汇合
    t1.detach(); // 不再要求主线程和线程汇合，二者各走各的
    // 调用detach()后无法继续join()
    cout<<"main"<<endl;
    cout<<t1.joinable()<<endl;
    cout<<"main2"<<endl;
 	return 0;
 }