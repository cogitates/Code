#include <bits/stdc++.h>
using namespace std;


// 指针无法控制所指向堆空间的生命周期
/*
智能指针：
1. 指针生命周期结束的时候主动释放堆空间
2. 一片堆空间最多只能由一个指针标识、
3. 杜绝指针运算和指针比较

智能指针的设计方案：
1. 通过类模板描述指针的行为
2. 重载指针特征操作符( -> and *),重载期间调用析构函数
3. 
*/

template <typename T>
class SmartPointer{
protected:
    T* pointer;
public:
    SmartPointer(T* p = NULL){
        pointer = p;
    }

    SmartPointer(const SmartPointer<T>& obj){
        pointer = obj.pointer;
        // obj.pointer = NULL;
        // const_cast 可以去掉一个对象的const属性
        // 保证同一片堆空间只能由一个指针标识
        const_cast<SmartPointer<T>&>(obj).pointer = NULL;
    }

    SmartPointer<T>& operator= (const SmartPointer<T>& obj){
        if(this != &obj){ // 防止自复制的情况
            delete pointer;
            pointer = obj.pointer;
            const_cast<SmartPointer<T>&>(obj).pointer = NULL;
        }
        return *this; // 可以支持连续赋值
    }

    ~SmartPointer(){
        delete pointer;
    }



    T* operator-> (){ // 重载->操作符
        return pointer;
    }

    T* operator* (){
        return *pointer;
    }

    bool isNull(){
        return (pointer == NULL);
    }

    T* get(){
        return pointer;
    }

};

class Test{
public:
    Test(){
        cout << "Test()" << endl;
    }
    ~Test(){
        cout << "~Test()" << endl;
    }
};
int main(){

    SmartPointer<Test> sp = new Test(); // 说明此时可以做到自动释放内存

    SmartPointer<Test> nsp;

    nsp = sp;

    cout<<sp.isNull()<<endl;
    cout<<nsp.isNull()<<endl;

    return 0;
}