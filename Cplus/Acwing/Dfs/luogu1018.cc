#include <bits/stdc++.h>
using namespace std;

int A,B,C;
vector<int> nums;
vector<int> temp(3);

void helper(vector<int>& nums, vector<int>& temp){
    for(int i = 1;i < 10;i+=3){
        temp[i/3] = nums[i-1] * 100 + nums[i] * 10 + nums[i+1];
    }
}


void dfs(vector<vector<int>>& res, int& length,vector<bool>& visited){
    if(length == 10){
        helper(nums,temp);
        // for(auto k : temp){
        //     cout<<k<<" ";
        // }
        // cout<<endl;
        if(B * temp[0] == A * temp[1] && C * temp[0] == A * temp[2]){
            res.push_back(temp);
            return ;
        }
            
    }

    for(int i = 1;i < 10;i++){
        if(!visited[i-1]){
            nums.push_back(i);
            visited[i-1] = true;
            length++;
            dfs(res,length,visited);
            length--;
            visited[i-1] = false;
            nums.pop_back();
        }
        
    }
}

int main(){
    vector<vector<int>> res;
    vector<bool> visited(9,false);
    cin>>A>>B>>C;
    int length = 1;
    dfs(res,length,visited);
    if(res.size() == 0){
        cout<<"No!!!"<<endl;
    }else{
        for(auto t : res){
            for(auto p : t){
                cout<<p<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}