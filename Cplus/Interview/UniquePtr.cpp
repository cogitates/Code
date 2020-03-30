#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
       }
};
// c++ unique_ptr智能指针
void f(int i,int j){
    ListNode* p = new ListNode(i);
    std::unique_ptr<ListNode> sp {new ListNode(j)};
    cout<<sp->val<<endl;
    cout<<p->val<<endl;

    delete p;
}

int main(){
    f(12,11);
    return 0;
}