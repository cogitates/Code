#include <bits/stdc++.h>
using namespace std;

// c++通过使用虚函数来实现多态
class Polygon{
protected:
    int w,h;
public:
    void set_value(int w,int h){
        this->w = w;
        this->h = h;
    }
    virtual int area() = 0;
    void show(){ cout<<area()<<endl;}
};

class Rectangle : public Polygon{
public:
    int area() {return w * h; }
};

class Triangle : public Polygon{
public:
    int area() {return w * h / 2;}
};

int main(){
    Polygon *p1 = new Rectangle;
    Polygon *p2 = new Triangle;
    p1->set_value(20,10);
    p2->set_value(20,10);
    p1->show();
    p2->show();
    delete p1;
    delete p2;

    cout<<sizeof(Polygon)<<endl;
    cout<<sizeof(int)<<endl;
    cout<<sizeof(char)<<endl;
    return 0;
}