// Produce and Consume multithread
// https://www.cnblogs.com/wxquare/p/7339739.html

#include <queue>
#include <iostream>
#include <condition_variable>
#include <mutex>
#include <thread>
using namespace std;


queue<int> q;
mutex m;
condition_variable cv1;
condition_variable cv2;


void Produce(int x){
    unique_lock<mutex> lck(m);
    while(q.size() >= 100){
        cv1.wait(lck);
    }
    q.push(x);
    cout<<"Produce:"<<x<<endl;
    if(q.size() >= 20) cv2.notify_all();
}

void Consume(){
    std::unique_lock<std::mutex> lck(m);
    while(q.size()<20) cv2.wait(lck);

    std::cout << "Consume:" << q.front() << std::endl;
    q.pop();
    if(q.size()<100) cv1.notify_all();
}


int main()
{
    std::thread Producers[200];
    for(int i=0;i<200;i++){
        Producers[i]=std::thread(Produce,i);
    }

    std::thread Consumers[200];
    for(int i=0;i<200;i++){
        Consumers[i] = std::thread(Consume);
    }

    for(auto& p : Producers){
        p.join();
    }
    for(auto& c : Consumers){
        c.join();
    }

    //std::cout << "Hello World!";
    return 0;
}