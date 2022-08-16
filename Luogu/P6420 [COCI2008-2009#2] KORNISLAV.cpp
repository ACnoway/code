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
int a[4];
int main()
{
    for(int i=0;i<4;++i) cin>>a[i];
    sort(a,a+4);
    cout<<a[0]*a[2];
    return 0;
}