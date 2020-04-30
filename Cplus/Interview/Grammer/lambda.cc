// Define of lambda expression
#include <bits/stdc++.h>
using namespace std;

// lambda表示式是一个对象
void lambda_1(){
    []{
        cout<<"lambda_1"<<endl;
    }();
    // 2
}


// 编译器实现原理
// 编译器实现 lambda 表达式大致分为一下几个步骤

// 创建 lambda 类，实现构造函数，使用 lambda 表达式的函数体重载 operator()（所以 lambda 表达式 也叫匿名函数对象）
// 创建 lambda 对象
// 通过对象调用 operator()

void lambda_2(){
    auto i = []{
        cout<<"lambda_2"<<endl;
    };
    i();
}
// &（以引用隐式捕获被使用的自动变量）
// = （以复制隐式捕获被使用的自动变量）
void lambda_3(){
    int id = 0;

    auto f = [id]() mutable { // 带mutable才能改变变量值
        cout<<"lambda_3:"<<"id:"<<id<<endl;
        ++id;  
    };
    f();
    cout<<id<<endl;
}

void lambda_4(){
    int id = 0;

    auto f = [&id]() mutable {
        cout<<"lambda_4:"<<"id:"<<id<<endl;
        ++id;  
    };
    f();
    cout<<id<<endl;
}

void lambda_5(){
    int x = 0;
    int y = 0;
    int z = 0;
    [x,&y](){
        cout<<"lambda_5:"<<endl;
        ++y;
    }();
    cout<<y<<endl;
}

void lambda_6(){
    int x = 0;
    int y = 0;
    int z = 0;
    [=,&y](){
        cout<<"lambda_5:"<<endl;
        ++y;
        cout<<"x"<<x<<endl;
        cout<<"z"<<z<<endl;
    }();
    cout<<y<<endl;
}

void lambda_7(){
    string name = "zxq";
    
    auto lambda = [name](string str) -> bool{
        cout<<"lambda_7:";
        return str == name;
    };
    cout<<lambda("good")<<endl;
    cout<<"sizeof lambda:"<<sizeof(lambda)<<endl;
    return ;
}

void lambda_8(){
    class Person{
    public:
        int age;
        Person(int x){
            age = x;
        }
    };
    auto cmp = [](const Person& a, const Person& b) -> bool{
        return a.age < b.age;
    };

    vector<Person> v = {Person(3), Person(2),Person(5)};
    sort(v.begin(),v.end(),cmp);

    for(int i = 0;i < 3;i++){
        cout<<v[i].age<<" ";
    }
    cout<<endl;
}

void lambda_9(){
    class Person{
    public:
        int age;
        Person(int x){
            age = x;
        }
    };
    auto cmp = [](const Person& a, const Person& b) -> bool{
        return a.age < b.age;
    };

    set<Person,decltype(cmp)> s(cmp);// c++ 11以后
    // set<Person,decltype(cmp)> s;// c++ 20以后
    s.insert(Person(3));
    s.insert(Person(2));
    s.insert(Person(5));

    for(auto it = s.begin();it != s.end();it++){
        cout<<(*it).age<<endl;
    }
}

void lambda_10(){
    vector<int> vi {5,20,3,123,433,12};
    int x = 15;
    int y = 200;
    cout<<"lambda_10"<<endl;
    vi.erase(remove_if(
        vi.begin(),
        vi.end(),
        [x,y](int n){ 
            return x < n && n < y;
        }
    ),
    vi.end()
    );
    for(auto i : vi){
        cout<<i<<" ";
    }
    cout<<endl;
}

int main(){
    // 1
    lambda_1();
    // 2
    lambda_2();
    // 3
    lambda_3();
    // 4
    lambda_4();
    // 5
    lambda_5();
    // 6
    lambda_6();
    // 7
    lambda_7();
    // 8
    lambda_8();
    // 9
    lambda_9();
    // 10
    lambda_10();
    return 0;
}