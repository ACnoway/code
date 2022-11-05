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
int n,m,q,l[2],r[2];
int a[100005],b[100005];
int main()
{
    cin>>n>>m>>q;
    for(int i=1;i<=n;++i) cin>>a[i];
    for(int i=1;i<=m;++i) cin>>b[i];
    int ma=1000000009,mi=-1;
    while(q--){
        ma=-1,mi=1000000009;
        for(int i=0;i<2;++i) cin>>l[i]>>r[i];
        for(int i=l[0];i<=r[0];++i) ma=max(ma,a[i]);
        for(int i=l[1];i<=r[1];++i) mi=min(mi,b[i]);
        cout<<(long long)ma*(long long)mi<<endl;
    }
    return 0;
}