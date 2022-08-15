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
    cin>>a[0]>>a[1]>>a[2];
    sort(a,a+3);
    if(a[1]-a[0]==a[2]-a[1]) cout<<a[2]+a[2]-a[1]<<endl;
    else{
        if(a[1]-a[0]>a[2]-a[1]) cout<<a[0]+a[2]-a[1]<<endl;
        else cout<<a[1]+a[1]-a[0]<<endl;
    }
    return 0;
}