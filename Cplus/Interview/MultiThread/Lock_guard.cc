// Lock_guard API
// https://paul.pub/cpp-concurrency/

#include <bits/stdc++.h>
using namespace std;

#include <thread>
#include <mutex>
#include <iostream>
 
int g_i = 0;
std::mutex g_i_mutex;  // ①
 
void safe_increment()
{
  // mutex是互斥信号量，也就是互斥访问标志
  // lock_guard是一个类模板，使我们可以免于手动锁定信号量mutex
  // 当mutex初始化，调用构造函数的时候加锁，销毁时调用析构函数解锁
  std::lock_guard<std::mutex> lock(g_i_mutex);  // ②
  ++g_i;

  std::cout << std::this_thread::get_id() << ": " << g_i << '\n';
  // ③
}
 
int main()
{
  std::cout << "main: " << g_i << '\n';
 
  std::thread t1(safe_increment); // ④
  std::thread t2(safe_increment);
 
  t1.join();
  t2.join();
 
  std::cout << "main: " << g_i << '\n';
}