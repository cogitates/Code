// make pair
// http://suo.im/5HXkPh
#include <memory>
#include <iostream>
#include <vector>
using namespace std;

class StructA {
public:
    int i;
    string str;
  
    StructA(int i) {
        this->i = i;
        cout << "StructA(int), line = " << __LINE__ << endl;
    };

    ~StructA() { cout << "~StructA " << endl; };

    void show() {
        cout << "show() is Called. line = " << __LINE__ << endl;
    }
};

void foo(shared_ptr<StructA> sp) {
    sp->show();
}

int main(int argc, const char* argv[]) {
    //make_shared自动申请对象及内存,自动释放,不用手动执行new和delete
    auto pA = make_shared<StructA>(123);
    auto pB = pA;
    cout << pA.use_count() << endl;
    auto k = pA.get();
    cout << k << endl;
    k->show();
    cout << "case1:";
    cout << "pA->i = " << pA->i << endl;
    cout << "case2:";
    foo(pA);
    return 0;
}