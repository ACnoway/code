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
typedef pair<int,int> pii;
int n,m,dfid;
int a[N];
vector<int> e[N];

//* -----树剖
int son[N],fa[N],dep[N],siz[N],top[N],dfn[N],nfd[N];
void dfs1(int x,int die){
    siz[x]=1;
    fa[x]=die;
    dep[x]=dep[die]+1;
    for(int v:e[x]){
        if(v==die) continue;
        dfs1(v,x);
        siz[x]+=siz[v];
        if(siz[v]>siz[son[x]]) son[x]=v;
    }
}
void dfs2(int x,int topf){
    top[x]=topf;
    dfn[x]=++dfid;
    nfd[dfid]=x;
    if(son[x]) dfs2(son[x],topf);
    for(int v:e[x]){
        if(v==fa[x]||v==son[x]) continue;
        dfs2(v,v);
    }
}
int LCA(int x,int y){
    while(top[x]!=top[y]){
        if(dep[top[x]]<dep[top[y]]) swap(x,y);
        x=fa[top[x]];
    }
    return (dep[x]<dep[y]?x:y);
}

//* --------线段树
struct info{
    int cnt,lft;
    bool operator<(const info &x)const{
        return (cnt==x.cnt?lft>x.lft:cnt<x.cnt);
    }
};
info operator+(const int &x,const info &y){
    return (info){x+y.cnt,y.lft};
}
struct vec{
    info f;
    int g;
};//单行向量
struct mat{
    info f[21];
    int g[21];
};//矩阵
vec operator+(const vec &x,const mat &y){
    vec c;
    c.f=min(x.f.cnt+y.f[x.f.lft],x.f.cnt+1+y.f[x.f.lft]);
    c.g=y.g[x.g];
    return c;
}
mat operator+(const mat &x,const mat &y){
    mat c;
    for(int i=0;i<20;++i){
        c.f[i]=min(x.f[i].cnt+y.f[x.f[i].lft],x.f[i].cnt+1+y.f[x.f[i].lft]);
        c.g[i]=y.g[x.g[i]];
    }
}
struct node{
    mat up,dw;
}t[N<<2];

void pushup(int x){
    t[x].up=t[x<<1].up+t[x<<1|1].up;
    t[x].dw=t[x<<1].dw+t[x<<1|1].dw;
}
void build(int x,int l,int r){
    if(l==r){
        mat now;
        now.f[0]={1,a[nfd[l]]-1};
        now.g[0]=a[nfd[l]]-1;
        for(int i=1;i<20;++i){
            now.f[i]={0,i-1};
            now.g[i]=max(a[nfd[l]],i)-1;
        }
        t[x].up=t[x].dw=now;
        return;
    }
    int mid=(l+r)>>1;
    build(x<<1,l,mid);
    build(x<<1|1,mid+1,r);
    pushup(x);
}
void modify(int x,int l,int r,int y){
    if(l==r){
        mat now;
        now.f[0]={1,a[nfd[l]]-1};
        now.g[0]=a[nfd[l]]-1;
        for(int i=1;i<20;++i){
            now.f[i]={0,i-1};
            now.g[i]=max(a[nfd[l]],i)-1;
        }
        t[x].up=t[x].dw=now;
        return;
        return;
    }
    int mid=(l+r)>>1;
    if(y<=mid) modify(x<<1,l,mid,y);
    else modify(x<<1|1,mid+1,r,y);
    pushup(x);
}
void jump1(int x,int l,int r,int L,int R,vec &ans){
    if(L<=l&&r<=R){
        ans=ans+t[x].up;
        return;
    }
    int mid=(l+r)>>1;
    if(L<=mid) jump1(x<<1,l,mid,L,R,ans);
    if(mid<R) jump1(x<<1|1,mid+1,r,L,R,ans);
}
void jump2(int x,int l,int r,int L,int R,vec &ans){
    if(L<=l&&r<=R){
        ans=ans+t[x].dw;
        return;
    }
    int mid=(l+r)>>1;
    if(L<=mid) jump2(x<<1,l,mid,L,R,ans);
    if(mid<R) jump2(x<<1|1,mid+1,r,L,R,ans);
}
int query(int s,int t){
    vec ans={{0,0},0};
    int lca=LCA(s,t);
    while(top[s]!=top[lca]){
        jump1(1,1,n,dfn[top[s]],dfn[s],ans);
        s=fa[top[s]];
    }
    if(s!=lca) jump1(1,1,n,dfn[lca]+1,dfn[s],ans);
    if(t!=lca){
        t=fa[t];
        vector<pii> st;
        while(top[t]!=top[lca]){
            st.emplace_back((pii){dfn[top[t]],dfn[t]});
            t=fa[top[t]];
        }
        if(dep[t]>=dep[lca]) st.emplace_back((pii){dfn})
    }
}
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    n=read();
    for(int i=1;i<=n;++i) a[i]=read();
    for(int i=1;i<n;++i){
        int u=read(),v=read();
        e[u].emplace_back(v);
        e[v].emplace_back(u);
    }
    dfs1(1,0);
    dfs2(1,1);
    build(1,1,n);
    m=read();
    while(m--){
        char op=getchar();
        int x=read(),y=read();
        if(op=='C'){
            a[x]=y;
            modify(1,1,n,dfn[x]);
        }
        else{
            query(x,y);
        }
    }
    return 0;
}