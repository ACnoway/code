#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#define int long long
#ifdef ONLINE_JUDGE
#define debug(x)
#else
#define debug(x) cout<<' '<<#x<<'='<<x<<endl;
#endif
using namespace std;
int n,x,ma;
int a[100005],f[100005];
signed main()
{
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>x;
        a[x]+=x;
        ma=max(ma,x);
    }
    f[1]=a[1];
    for(int i=2;i<=ma+1;++i){
        f[i]=max(f[i-1],f[i-2]+a[i]);
    }
    cout<<f[ma]<<endl;
    return 0;
}