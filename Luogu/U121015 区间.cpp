#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
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
const int N=1000006;
int n,l,r,c1,c2;
int a[N],b[N],c[N],bit[N],s1[N],s2[N];
inline int lb(int x){return x&(-x);}
inline void add(int x){
    while(x<=n){
        bit[x]++;
        x+=lb(x);
    }
}
inline int query(int x){
    int res=0;
    while(x){
        res+=bit[x];
        x-=lb(x);
    }
    return res;
}
signed main()
{
    // freopen("niu.in","r",stdin);
    // freopen("niu.out","w",stdout);
    n=read();
    l=read(); r=read();
    for(int i=1;i<=n;++i){
        a[i]=read();
        s1[i]=a[i]-r+s1[i-1];
        s2[i]=a[i]-l+s2[i-1];
        b[i]=s1[i]; c[i]=s2[i];
        if(s1[i]<=0) ++c1;
        if(s2[i]<0) ++c2;
    }
    sort(b+1,b+1+n);
    sort(c+1,c+1+n);
    int m1=unique(b+1,b+1+n)-b-1,m2=unique(c+1,c+1+n)-c-1;
    for(int i=1;i<=n;++i){
        s1[i]=lower_bound(b+1,b+m1+1,s1[i])-b;
        s2[i]=lower_bound(c+1,c+m2+1,s2[i])-c;
    }
    for(int i=n;i;i--){
        c1+=query(s1[i]);
        add(s1[i]);
    }
    memset(bit,0,sizeof(bit));
    for(int i=n;i;i--){
        c2+=query(s2[i]-1);
        add(s2[i]);
    }
    int ans=c1-c2,nn=(n+1)*n/2;
    int d=__gcd(ans,nn);
    if(ans==nn) printf("1");
    else if(ans==0) printf("0");
    else printf("%lld/%lld",ans/d,nn/d);
    return 0;
}