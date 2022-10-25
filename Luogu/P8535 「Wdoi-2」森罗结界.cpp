#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#ifdef ONLINE_JUDGE
#define debug(x)
#else
#define debug(x) cout<<' '<<#x<<'='<<x<<endl;
#endif
using namespace std;
int n;
int num[10]={24,5,8,15,30,23,11,16,10,18};
string ans;
int main()
{
    cin>>n;
    if(n%5>=3) putchar('2'),n-=8;
    for(int i=1;i<=n/5;++i) putchar('1');
    return 0;
}