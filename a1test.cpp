#include <bits/stdc++.h>
using namespace std;
int fac[100]={1,2,3,4,5,6,7,8,9,10};
const int B=2;
const int mod=2147483647;
inline FAC(int n)
{
    int x = n / B, t = fac[x];
    for (int i = x * B + 1; i <= n; ++i) t = 1ll * t * i % mod;
    return t; 
}
int main()
{
    cout<<FAC(5)<<endl;
    return 0;
}
