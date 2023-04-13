#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#define int long long
#ifdef ONLINE_JUDGE
#define debug(x)
#else
#define debug(x) cout<<' '<<#x<<'='<<x<<endl
#endif
using namespace std;
inline int read(){
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-') f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+(c^48);
        c=getchar();
    }
    return x*f;
}
const int N=5e5+10;
int n,m,l,r,s,e,ans;
int a[N],f[N];
signed main()
{
    n=read(); m=read();
    while(m--){
        l=read(); r=read();
        s=read(); e=read();
        int d=(e-s)/(r-l);
        f[l]+=s;
        a[l+1]+=d;
        a[r+1]-=e;
    }
    for(int i=1;i<=n;++i) a[i]+=a[i-1];
    for(int i=1;i<=n;++i) f[i]+=f[i-1]+a[i],ans^=f[i];
    printf("%lld\n",ans);
    return 0;
}