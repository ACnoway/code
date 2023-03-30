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
const int N=2000006;
int n,m;
int xs[N];
struct smx{
    int l,r,h,w;
    bool operator <(const smx &x)const{
        return h<x.h;
    }
}lines[N];
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
    if(!t[x].sum){
        t[x].len=t[lson].len+t[rson].len;
    }
    else{
        t[x].len=xs[r+1]-xs[l];
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
        lines[(i<<1)-1]={xa,xb,ya,1};
        lines[i<<1]={xa,xb,yb,-1};
        //加边，下面的横线权值为1
        //上面的权值为-1
        //类似于差分，扫上去时做类似前缀和的操作
        xs[(i<<1)-1]=xa;
        xs[i<<1]=xb;
        //x去重
    }
    n<<=1;
    sort(lines+1,lines+n+1);
    //按照y排序，保证扫上去的时候从小到大
    sort(xs+1,xs+n+1);
    m=unique(xs+1,xs+n+1)-xs-1;
    build(1,1,m-1);
    //m-1是因为每个节点的l和r分别为xs[l]和xs[r+1]
    int ans=0;
    for(int i=1;i<n;++i){
        gai(1,lines[i].l,lines[i].r,lines[i].w);
        //扫到这个线段就把它加进线段树里
        ans+=t[1].len*(lines[i+1].h-lines[i].h);
        //这里len已经是更新好了的，可以直接统计答案
    }
    printf("%lld\n",ans);
    return 0;
}