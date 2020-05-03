// Right value
// https://www.bilibili.com/video/BV1p4411v7Dh?p=23

#include <bits/stdc++.h>
using namespace std;

class MyString { 
private: 
    char* _data; 
    size_t   _len; 
    void _init_data(const char *s) { 
    _data = new char[_len+1]; 
    memcpy(_data, s, _len); 
    _data[_len] = '\0'; 
    } 
public: 
    MyString() { 
    _data = NULL; 
    _len = 0; 
    } 

    MyString(const char* p) { 
    _len = strlen (p); 
    _init_data(p); 
    } 

    MyString(const MyString& str) {  //深拷贝
    _len = str._len; 
    _init_data(str._data); 
    std::cout << "Copy Constructor is called! source: " << str._data << std::endl; 
    } 

    MyString& operator=(const MyString& str) { 
    if (this != &str) { //拷贝复制的防御性声明，防止自引用
        _len = str._len; 
        _init_data(str._data); 
    } 
    std::cout << "Copy Assignment is called! source: " << str._data << std::endl; 
    return *this; 
    } 

    MyString(MyString&& str) { 
    std::cout << "Move Constructor is called! source: " << str._data << std::endl; 
    _len = str._len; 
    _data = str._data; 
    str._len = 0; 
    str._data = NULL; 
    }

    MyString& operator=(MyString&& str) {  // &&就是指明使用右值的
    std::cout << "Move Assignment is called! source: " << str._data << std::endl; 
    if (this != &str) { // 浅拷贝
        _len = str._len; 
        _data = str._data; 
        str._len = 0; 
        str._data = NULL; // 将初始指针置为空
    } 
    return *this; 
    }

    virtual ~MyString() { 
    if (_data) free(_data); 
    } 
}; 
 
int main() { 
 MyString a; 
 a = MyString("Hello"); 
 std::vector<MyString> vec; 
 vec.push_back(MyString("World"));  // mMyString() 这是一个右值，也可以算是一个临时变量
}