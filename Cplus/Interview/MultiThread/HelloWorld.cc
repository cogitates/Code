#include <iostream>
#include <thread>
using namespace std;
 
//This function will be called from a thread
//该函数将在一条线程中得到调用
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
	//Join the thread with the main thread
	//和主线程协同
 	t1.join(); //阻塞主线程，等待对应线程执行完毕，相当于把当前进程执行完后merge到主线程
	// join()会在线程结束后，释放线程的资源和内存
 	return 0;
 }