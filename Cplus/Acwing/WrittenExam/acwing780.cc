// acwing 780 爱健身的小王
// https://www.acwing.com/problem/content/782/

#include <bits/stdc++.h>
using namespace std;

/*
首先分析一下小王会在哪里停下来。小王从起点走n+1步后打了第一个标记，我们记为A点，再走n+1步又打一个标记，记为B点，以此类推。
假设小王打了若干次标记后不是在A点停下来，比如是在B点停下来，那么往回退n+1步，小王上一次一定是在A点重复打了一个标记，这就有矛盾了
所以，小王一定是在A点停下来的。这个结论一旦成立，说明小王在A点重复打标记之前的一次就是在原点打标记。
我们记小王一共标记了m次，那么在原点打标记就是第m-1次打标记，而每打一次标记要走n+1步
所以到第m-1次打标记为止一共走了(n+1)(m-1)步，这(n+1)(m-1)步刚好等于周长的若干倍，即
(n+1)(m-1)=4n*k
从这个式子中可以看出，(n+1)(m-1)既是n+1的倍数，也是4n的倍数
又因为我们要找的m是让上式第一次成立的m，所以我们只要找出n+1和4n的最小公倍数，然后除以n+1即可得到答案。
所以m=[n+1, 4n] / (n+1) + 1
而最小公倍数[n+1, 4n] = (n+1)*4n / (n+1, 4n)
所以m = 4n / (n+1, 4n) + 1
*/
// [a,b] * (a,b) = a * b 最大公约 * 最小公倍 == a * b


// int gcd(int a, int b){
//     return b ? gcd(b,a%b) : a;
// }

int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin>>n;
        // int d = gcd(4*n,n+1);
        std::function<int(int, int)> gcd = [&](int a, int b){
            return b == 0 ? a : gcd(b, a%b);
        };
        int d = gcd(4*n,n+1);
        cout<<4*n/d+1<<endl;
    }
    return 0;
}