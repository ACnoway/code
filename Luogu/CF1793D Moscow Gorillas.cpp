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
const int N=200005;
int n;
int p[N],q[N],s[N],t[N];
signed main()
{
    n=read();
    for(int i=1;i<=n;++i){
        p[i]=read();
        s[p[i]]=i;
    }
    for(int i=1;i<=n;++i){
        q[i]=read();
        t[q[i]]=i;
    }
    int si=s[1],ti=t[1],ans=0;
    if(si>ti) swap(si,ti);
    if(si) ans+=si*(si-1)>>1;
    if(ti>si) ans+=(ti-si)*(ti-si-1)>>1;
    if(n>ti) ans+=(n-ti+1)*(n-ti)>>1;
    int l=si,r=ti;
    for(int m=2;m<=n;++m){
        si=s[m];
        ti=t[m];
        if(si>ti) swap(si,ti);
        if(l>ti) ans+=(l-ti)*(n-r+1);
        if(r<si) ans+=(si-r)*l;
        if(si<l&&r<ti) ans+=(l-si)*(ti-r);
        l=min(l,si);
        r=max(r,ti);
    }
    printf("%lld\n",ans+1);
    return 0;
}