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
int n,m;
long long a[1000006];
int main()
{
    cin>>n>>m;
    if(n==1){
        cout<<0;
        return 0;
    }
    long long mi=10000000000,ma=0;
    for(int i=0;i<n;++i) cin>>a[i],mi=min(mi,a[i]),ma=max(ma,a[i]);
    for(int i=0;i<m;++i){
        if(ma<2) ma+=2;
        else ma<<=1;
    }
    debug(ma);
    debug(mi);
    cout<<ma-mi<<endl;
    return 0;
}