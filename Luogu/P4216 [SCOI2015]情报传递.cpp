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
const int N=200005,M=400005;
int n,q;
int ans[N];
struct node{
    int to,nxt;
}e[M];
int idx,head[N];
void addedge(int u,int v){
    e[++idx].to=v;
    e[idx].nxt=head[u];
    head[u]=idx;
}
//* -----树剖
int dfid,dfn[N];
int son[N],fa[N],dep[N],siz[N],top[N];
bool vis[N];
void dfs1(int x){
    siz[x]=1;
    vis[x]=1;
    dep[x]=dep[fa[x]]+1;
    dfn[x]=++dfid;
    int v;
    for(int i=head[x];i;i=e[i].nxt){
        v=e[i].to;
        if(vis[v]) continue;
        dfs1(v);
        siz[x]+=siz[v];
        if(siz[v]>siz[son[x]]) son[x]=v;
    }
}
void dfs2(int x,int topf){
    top[x]=topf;
    int v;
    if(son[x]) dfs2(son[x],topf);
    for(int i=head[x];i;i=e[i].nxt){
        v=e[i].to;
        if(v==fa[x]||v==son[x]) continue;
        dfs2(v,v);
    }
}
//* -----树状数组
int tree[N<<2];
inline int lowbit(int x){
    return x&(-x);
}
inline void add(int x,int k){
    for(;x<=n;x+=lowbit(x)){
        tree[x]+=k;
    }
}
inline int query(int x){
    int sum=0;
    for(;x;x-=lowbit(x)){
        sum+=tree[x];
    }
    return sum;
}
struct wenti{
    int op,x,y,c;
    vector<int> id;
    wenti(){
        op=x=y=c=0;
        id.clear();
    }
}qs[N];
inline int LCA(int x,int y){
    while(top[x]^top[y]){
        if(dep[top[x]]>dep[top[y]]) x=fa[top[x]];
        else y=fa[top[y]];
    }
    return dep[x]>dep[y]?y:x;
}
inline int dis(int x,int y){
    return dep[x]+dep[y]-(dep[LCA(x,y)]<<1)+1;
}
inline int qq(int x,int y){
    int lca=LCA(x,y);
    return query(dfn[x])+query(dfn[y])-query(dfn[lca])-query(dfn[fa[lca]]);
}
int main()
{
    n=read();
    int st;
    for(int i=1;i<=n;++i){
        fa[i]=read();
        if(!fa[i]) st=i;
        addedge(fa[i],i);
    }
    dfs1(st); dfs2(st,st);
    q=read();
    for(int i=1;i<=q;++i){
        qs[i].op=read();
        if(qs[i].op==1){
            qs[i].x=read();
            qs[i].y=read();
            qs[i].c=read();
            if(qs[i].c<i) qs[i-qs[i].c-1].id.push_back(i);
        }
        else{
            qs[i].x=read();
        }
    }
    int op,x,y,c;
    for(int i=1;i<=q;++i){
        op=qs[i].op;
        debug(op);
        x=qs[i].x; y=qs[i].y;
        c=qs[i].c;
        if(op==2){
            add(dfn[x],1);
            add(dfn[x]+siz[x],-1);
        }
        for(int v:qs[i].id) ans[v]=qq(qs[v].x,qs[v].y);
        if(op==1){
            debug(i);
            printf("%d %d\n",dis(x,y),ans[i]);
        }
    }
    return 0;
}