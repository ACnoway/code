#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
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
const int N=1000005;
int n,m,dfid;
int a[N],fa[N],dfn[N];
vector<int> e[N];
void dfs(int x,int die){
    fa[x]=die;
    dfn[x]=++dfid;
    for(int v:e[x]){
        if(v==die) continue;
        dfs(v,x);
    }
}

//* -----树剖
int son[N],fa[N],dep[N],siz[N],top[N];
bool vis[N];
void dfs1(int x,int die){
    siz[x]=1;
    vis[x]=1;
    dep[x]=dep[die]+1;
    fa[x]=die;
    for(int v:e[x]){
        if(vis[v]) continue;
        dfs1(v,x);
        siz[x]+=siz[v];
        if(siz[v]>siz[son[x]]) son[x]=v;
    }
}
void dfs2(int x,int topf){
    top[x]=topf;
    if(son[x]) dfs2(son[x],topf);
    for(int v:e[x]){
        if(v==fa[x]||v==son[x]) continue;
        dfs2(v,v);
    }
}

//* --------线段树
int v[N<<2];
void build(int x,int l,int r){
    if(l==r){
        v[x]=a[l];
        return;
    }
    int mid=(l+r)>>1;
    build(x<<1,l,mid);
    build(x<<1|1,mid+1,r);
    v[x]=max(v[x<<1],v[x<<1|1]);
}
void modify(int x,int l,int r,int k,int y){
    if(l==y&&r==y){
        v[x]=k;
        return;
    }
    int mid=(l+r)>>1;
    if(y<=mid) modify(x<<1,l,mid,k,y);
    else modify(x<<1|1,mid+1,r,k,y);
    v[x]=max(v[x<<1],v[x<<1|1]);
}
int query(int x,int l,int r,int L,int R){
    // debug(x);
    if(L<=l&&r<=R){
        return v[x];
    }
    int mid=(l+r)>>1,s=0;
    if(mid>=L) s=max(s,query(x<<1,l,mid,L,R));
    if(mid<R) s=max(s,query(x<<1|1,mid+1,r,L,R));
    return s;
}
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;++i) cin>>a[i];
    
    return 0;
}