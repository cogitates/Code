// mutex lock
// https://paul.pub/cpp-concurrency/
#include <bits/stdc++.h>
using namespace std;
static const int MAX = 10e8;
static double sum = 0;
/*
我们用锁的粒度（granularity）来描述锁的范围。
细粒度（fine-grained）是指锁保护较小的范围，粗粒度（coarse-grained）是指锁保护较大的范围。
出于性能的考虑，我们应该保证锁的粒度尽可能的细。
并且，不应该在获取锁的范围内执行耗时的操作，例如执行IO。如果是耗时的运算，也应该尽可能的移到锁的外面。
*/
// mutex是mutual exclusion（互斥）的简写。
static mutex exclusive;
/*
when the lock is not good
void concurrent_worker(int min, int max) { 
  for (int i = min; i <= max; i++) {
    exclusive.lock();
    sum += sqrt(i);
    exclusive.unlock();
  }
}
hardware_concurrency: 8
Concurrent task finish, 114425 ms consumed, Result: 2.10819e+13
when the lock is right --> very fast and make full use of computer
*/

void concurrent_worker(int min, int max) {
  double tmp_sum = 0;
  for (int i = min; i <= max; i++) {
    tmp_sum += sqrt(i); // ①
  }
  exclusive.lock(); // ②
  sum += tmp_sum;
  exclusive.unlock();
}
// hardware_concurrency: 8
// Concurrent task finish, 691 ms consumed, Result: 2.10819e+13
void concurrent_task(int min, int max) {
  auto start_time = chrono::steady_clock::now();

  unsigned concurrent_count = thread::hardware_concurrency();
  cout << "hardware_concurrency: " << concurrent_count << endl;
  vector<thread> threads;
  min = 0;
  sum = 0;
  for (int t = 0; t < concurrent_count; t++) {
    int range = max / concurrent_count * (t + 1);
    threads.push_back(thread(concurrent_worker, min, range));
    min = range + 1;
  }
  for (int i = 0; i < threads.size(); i++) {
    threads[i].join();
  }

  auto end_time = chrono::steady_clock::now();
  auto ms = chrono::duration_cast<chrono::milliseconds>(end_time - start_time).count();
  cout << "Concurrent task finish, " << ms << " ms consumed, Result: " << sum << endl;
}

int main() {
  concurrent_task(0, MAX);
  return 0;
}