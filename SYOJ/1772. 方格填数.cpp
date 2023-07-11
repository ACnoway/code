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
int n,k,ans;
int f[55][10];
signed main()
{
    freopen("b.in","r",stdin);
    freopen("b.out","w",stdout);
    cin>>n>>k;
    f[0][0]=1;
    for(int i=1;i<=n;++i){
        for(int j=0;j<k;++j) f[i][0]+=f[i-1][j];
        for(int j=1;j<k;++j) f[i][j]=f[i-1][j-1];
    }
    for(int i=0;i<k;++i) ans+=f[n][i];
    cout<<ans<<endl;
    return 0;
}