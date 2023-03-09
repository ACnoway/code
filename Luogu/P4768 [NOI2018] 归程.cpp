#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<queue>
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
const int N=200005,M=800010;
int T,n,m;
//---输入图---
struct node{
    int u,v,cd,hb;
}edge[M];
//---新图---
struct Node{
    int to,nxt,cd,hb;
}e[M<<1];
int idx,head[N];
void addedge(int x,int y,int w1,int w2){
    e[++idx].to=y;
    e[idx].nxt=head[x];
    e[idx].cd=w1;
    e[idx].hb=w2;
    head[x]=idx;
}
//-----并查集-----
int p[N];
int find(int x){
    if(p[x]!=x) p[x]=find(p[x]);
    return p[x];
}
void merge(int x,int y){
    p[find(x)]=find(y);
}
//-----树剖-----
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
//-----迪杰斯特拉-----
struct bian{
    int to,nxt,dis;
}E[M<<1];
int didx,dh[N];
struct dnode{
    int dis,pos;
    bool operator <(const dnode b)const{
        return b.dis<dis;
    }
};
priority_queue<dnode> q;
int Dis[N];
bool dvis[N];
inline void dij(){
    for(int i=2;i<=n;++i) Dis[i]=INT_MAX;
    Dis[1]=0;
    q.push({0,1});
    dnode tmp;
    int x,y,d;
    while(!q.empty()){
        tmp=q.top();
        q.pop();
        x=tmp.pos;d=tmp.dis;
        if(vis[x]) continue;
        vis[x]=1;
        for(int i=dh[x];i;i=E[i].nxt){
            y=e[i].to;
            if(Dis[y]>Dis[x]+E[i].dis){
                Dis[y]=Dis[x]+E[i].dis;
                if(!vis[y]){
                    q.push({Dis[y],y});
                }
            }
        }
    }
}
int main()
{
    T=read();
    while(T--){
        n=read();
        m=read();
        //初始化
        for(int i=1;i<=n;++i) p[i]=i;
        for(int i=1;i<=m;++i){
            edge[i].u=read();
            edge[i].v=read();
            edge[i].cd=read();
            edge[i].hb=read();
        }
        
    }
    return 0;
}