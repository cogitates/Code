#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin>>N;
    vector<int> price(N+1,0);
    for(int i = 1;i <= N;i++){
        cin>>price[i];
    }

    sort(price.begin(),price.end());
    int result = 0;
    if(N == 1) cout<<price[1]<<endl;
    else if(N == 2) cout<<price[1]+price[2]<<endl;
    else{
        for(int index = N;index >= 1;index--){
            int k = 3;
            while(k--){
                if(k != 1){
                    result += price[index];
                }else{
                    continue;
                }
                index--;
                if(index <= 1) break;
                cout<<result<<endl;
            }
        }
    }
    
    cout<<result<<endl;
}