#include <iostream>
#include <thread>
using namespace std;
 
//This function will be called from a thread
//该函数将在一条线程中得到调用
 void call_from_thread()
 {
 	cout << "hello world!" << endl;
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
 	t1.join();
 	return 0;
 }