#include <bits/stdc++.h>
using namespace std;

// return x/y.
int divs(const int x, const int y)
{
    if(y == 0){
        exit(1);
    }
    if(x < y){
        return 0;
    }
    if(x == y){
        return 1;
    }

    int left = x;
    int result = 0;
    while(left >= y){
        int mul = 1;
        cout<<"left"<<left<<" ";
        while(y * mul <= (left >> 1)){ // 这里left本身并没有改变,这是为了避免mul回滚
            cout<<"left"<<left<<endl;
            mul = mul * 2;
        }
        result += mul;
        left -= y * mul; // 只有这里是让left减下来的
    }
    return result;
}

int main(){
    cout<< divs(120,6) <<endl;
    return 0;
}