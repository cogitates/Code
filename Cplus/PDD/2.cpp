#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,M ;
    cin >> N >> M;
    vector<long long int> prefix(N+1,0);
    vector<long long int> arr(N+1,0);
    long long int sum = 0;
    // long long int temp;
    for(int i = 1;i <= N;i++){
        cin >> arr[i];
        sum += arr[i];
        prefix[i] = sum;
        // cout<<prefix[i]<<endl;
    }
    
    vector<vector<bool> > f(N+1,vector<bool>(N+1,false));
    

    for(int i = 1;i <= N;i++){
        for(int j = i;j <= N;j++){
            if(i == j) f[i][j] = (arr[i] < M ? 0 :arr[i] % M == 0);
            else{
                long long int temp = prefix[j] - prefix[i-1];
                if(temp < M) f[i][j] = 0;
                else f[i][j] = (temp % M == 0);
            }
        }
    }
    long long int result = 0;
    for(int i = 1;i <= N;i++){
        for(int j = 1;j <= N;j++){
            if(f[i][j]) result++;
        }
    }


    cout << result << endl;
    return 0;
}