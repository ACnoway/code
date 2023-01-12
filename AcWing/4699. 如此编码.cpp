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
int n,m,bef;
int a[30];
int main()
{
    cin>>n>>m;
    a[0]=1;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        a[i]*=a[i-1];
        cout<<(m%a[i]-bef)/a[i-1]<<' ';
        bef=m%a[i];
    }
    return 0;
}