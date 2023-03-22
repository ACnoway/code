#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#define lson x<<1
#define rson x<<1|1
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
int n,m;
int xs[N<<1];
struct smx{
    int l,r,h,w;
    bool operator <(const smx &x)const{
        return h<x.h;
    }
}lines[N<<1];
struct node{
    int l,r,sum,len;
}t[N<<2];
void build(int x,int l,int r){
    t[x].l=l;
    t[x].r=r;
    t[x].len=t[x].sum=0;
    if(l==r) return;
    int mid=(l+r)>>1;
    build(lson,l,mid);
    build(rson,mid+1,r);
}
void pushup(int x){
    int l=t[x].l,r=t[x].r;
    if(t[x].sum){
        t[x].len=xs[r+1]-xs[l];
    }
    else{
        t[x].len=t[lson].len+t[rson].len;
    }
}
void gai(int x,int L,int R,int k){
    int l=t[x].l,r=t[x].r;
    if(xs[r+1]<=L||R<=xs[l]) return;
    if(L<=xs[l]&&xs[r+1]<=R){
        t[x].sum+=k;
        pushup(x);
        return;
    }
    gai(lson,L,R,k);
    gai(rson,L,R,k);
    pushup(x);
}

signed main()
{
    n=read();
    int xa,xb,ya,yb;
    for(int i=1;i<=n;++i){
        xa=read(); ya=read();
        xb=read(); yb=read();
        xs[i<<1-1]=xa; xs[i<<1]=xb;
        lines[i<<1-1]={xa,xb,ya,1};
        lines[i<<1]={xa,xb,yb,-1};
    }
    n<<=1;
    sort(xs+1,xs+n+1);
    sort(lines+1,lines+n+1);
    m=unique(xs+1,xs+n+1)-xs-1;
    build(1,1,m-1);
    int ans=0;
    for(int i=1;i<n;++i){
        gai(1,lines[i].l,lines[i].r,lines[i].w);
        ans+=t[1].len*(lines[i+1].h-lines[i].h);
    }
    printf("%lld\n",ans);
    return 0;
}