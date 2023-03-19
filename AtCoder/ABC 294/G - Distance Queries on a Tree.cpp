#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
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
const int N=200005,M=200005;
int n,m;
struct node{
    int to,nxt;
}e[M];
int idx,head[N];
void add(int u,int v){
    e[++idx].to=v;
    e[idx].nxt=head[u];
    head[u]=idx;
}
//* -----树剖
int son[N],fa[N],dep[N],siz[N],top[N];
bool vis[N];
void dfs1(int x,int die){
    siz[x]=1;
    vis[x]=1;
    int v;
    for(int i=head[x];i;i=e[i].nxt){
        v=e[i].to;
        if(vis[v]) continue;
        dep[v]=dep[x]+1;
        fa[v]=x;
        dfs1(v,x);
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
int main()
{
    
    return 0;
}