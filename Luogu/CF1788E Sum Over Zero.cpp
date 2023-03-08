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
const int N=2000005;
int n;
int a[N],f[N],t[N],id[N];
struct node{
    int v,p;
    bool operator <(const node b)const{
        if(v==b.v) return p<b.p;
        return v<b.v;
    }
}m[N];
bool up[N];
inline int lowbit(int x){
    return x&(-x);
}
inline void update(int x,int y){
    for(;x<=n;x+=lowbit(x)){
        t[x]=max(t[x],y);
    }
}
inline int query(int x){
    int sum=LONG_LONG_MIN;
    for(;x;x-=lowbit(x)){
        sum=max(sum,t[x]);
    }
    return sum;
}
signed main()
{
    n=read();
    for(int i=1;i<=n;++i){
        t[i]=LONG_LONG_MIN;
        a[i]=read();
        f[i]=f[i-1]+a[i];
        if(f[i]>=0) up[i]=1;
        m[i].v=f[i];
        m[i].p=i;
    }
    sort(m+1,m+n+1);
    for(int i=1;i<=n;++i){
        id[m[i].p]=i;
    }
    int ma=0,dp=0;
    ma=dp=up[1];
    for(int i=2;i<=n;++i){
        if(up[i]) dp=i;
        else dp=LONG_LONG_MIN;
        update(id[i-1],ma-(i-1));
        int tmp=query(id[i]);
        if(tmp!=LONG_LONG_MIN) dp=max(dp,tmp+i);
        ma=max(ma,dp);
    }
    printf("%lld\n",ma);
    return 0;
}