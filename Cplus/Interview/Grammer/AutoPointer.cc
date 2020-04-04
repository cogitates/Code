#include <bits/stdc++.h>
using namespace std;

// auto_ptr 是一个类模板
/*
它存储的是一个指向Type的指针。

template <typename Type>
class auto_ptr {...};
*/

int main(){
    auto_ptr<string> ap{new string{"i am a test."}};
    auto_ptr<string> nap;

    nap = ap;

    // cout<<*ap<<endl; 此时ap指针已经不再指向string
    cout << *nap << endl;
    return 0;
}