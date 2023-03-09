#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<climits>
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
const int N=1e5+10,M=5e5+10;
int n,m,q,cnt;
int p[N],val[N<<2];
int fa[N],dep[N],top[N],son[N],siz[N];
bool vis[N<<2];
struct node{
    int x,y,dis;
}edge[M];
bool cmp(node a,node b){
    return a.dis>b.dis;
}
struct Node{
    int to,nxt;
}e[M<<1];
int idx,head[N];
int find(int x){
    if(p[x]!=x) p[x]=find(p[x]);
    return p[x];
}
inline void merge(int x,int y){
    p[find(x)]=find(y);
}
inline void addedge(int u,int v){
    e[++idx].to=v;
    e[idx].nxt=head[u];
    head[u]=idx;
}
//---树剖---
void dfs1(int x,int die){
    siz[x]=1;
    vis[x]=1;
    int v;
    for(int i=head[x];i;i=e[i].nxt){
        v=e[i].to;
        if(v==die) continue;
        dep[v]=dep[x]+1;
        fa[v]=x;
        dfs1(v,x);
        siz[x]+=siz[v];
        if(siz[v]>siz[son[x]]) son[x]=v;
    }
}
void dfs2(int x,int topf){
    top[x]=topf;
    if(son[x]) dfs2(son[x],topf);
    int v;
    for(int i=head[x];i;i=e[i].nxt){
        v=e[i].to;
        if(v==fa[x]||v==son[x]) continue;
        dfs2(v,v);
    }
}
inline void kruskal(){
    sort(edge+1,edge+1+m,cmp);
    for(int i=1;i<=n;++i) p[i]=i;
    int x,y;
    for(int i=1;i<=m;++i){
        x=find(edge[i].x);
        y=find(edge[i].y);
        if(x!=y){
            val[++cnt]=edge[i].dis;
            p[cnt]=p[x]=p[y]=cnt;
            addedge(x,cnt);
            addedge(y,cnt);
            addedge(cnt,x);
            addedge(cnt,y);
        }
    }
    for(int i=1;i<=cnt;++i){
        if(!vis[i]){
            x=find(i);
            dfs1(x,0);
            dfs2(x,x);
        }
    }
}
int lca(int x,int y){
    while(top[x]!=top[y]){
        if(dep[top[x]]>dep[top[y]]) x=fa[top[x]];
        else y=fa[top[y]];
    }
    return (dep[x]<dep[y]?x:y);
}
int main()
{
    n=read();
    m=read();
    cnt=n;
    for(int i=1;i<=m;++i){
        edge[i].x=read();
        edge[i].y=read();
        edge[i].dis=read();
    }
    kruskal();
    q=read();
    int x,y;
    while(q--){
        x=read();
        y=read();
        if(find(x)!=find(y)) printf("-1\n");
        else printf("%d\n",val[lca(x,y)]);
    }
    return 0;
}