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
int a[6],b[6];
int main()
{
    b[0]=1;
    b[1]=1;
    b[2]=2;
    b[3]=2;
    b[4]=2;
    b[5]=8;
    for(int i=0;i<6;++i) cin>>a[i],cout<<b[i]-a[i]<<' ';
    return 0;
}