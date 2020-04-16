#include <bits/stdc++.h>
using namespace std;

class Fraction // 分数类
{
public:
    Fraction(int num,int den = 1) : son(num),mum(den) {}
    operator double() const{ // 转换函数，无需返回类型
        return (double) (son / mum);
    } 
private:
    int son;
    int mum;
};

int main(){
    Fraction f(10,2);
    cout<<(double)f<<endl;
    return 0;
}