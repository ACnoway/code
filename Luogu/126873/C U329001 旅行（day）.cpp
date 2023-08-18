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
const int N=2e5+10;
int n,m,S,T,ans=1145141919;
int idx=1,head[N<<1],to[N<<1],nxt[N<<1],w[N<<1];
bool vis[N];
typedef pair<int,int> pii;
void addedge(int u,int v,int _w){
    to[++idx]=v;
    w[idx]=_w;
    nxt[idx]=head[u];
    head[u]=idx;
}
void bfs(){
    queue<pii> q;
    pii p;
    q.emplace((pii){S,0});
    vis[S]=1;
    while(!q.empty()){
        p=q.front();
        q.pop();
        int u=p.first,d=p.second+1,v;
        for(int i=head[u];i;i=nxt[i]){
            v=to[i];
            if(v==T){
                ans=min(ans,d);
                continue;
            }
            if(!vis[v]){
                q.emplace((pii){v,d});
                vis[v]=1;
            }
        }
    }
}
// int dis[N];
// bool vis[N];
// int idx=1,head[N<<1],to[N<<1],nxt[N<<1],w[N<<1];
// void addedge(int u,int v,int _w){
//     to[++idx]=v;
//     w[idx]=_w;
//     nxt[idx]=head[u];
//     head[u]=idx;
// }
// typedef pair<int,int> pii;
// bool operator <(pii &x,pii &y){
//     return y.first<x.first;
// }
// priority_queue<pii> q;
// void dij(){
//     dis[S]=0;
//     q.emplace((pii){-1,S});
//     pii p;
//     while(!q.empty()){
//         p=q.top();
//         q.pop();
//         int x=p.second,d=p.first,v,ndis;
//         if(vis[x]) continue;
//         vis[x]=1;
//         for(int i=head[x];i;i=nxt[i]){
//             v=to[i];
//             if((d+1)%7>w[i]){
//                 ndis=d+(7-(d+1)%7+w[i]);
//             }
//             else{
//                 ndis=d+w[i]-d%7;
//             }
//             if(dis[v]>ndis){
//                 dis[v]=ndis;
//                 if(!vis[v]) q.emplace((pii){dis[v],v});
//             }
//         }
//     }
// }
int main()
{
    n=read();
    m=read();
    S=read();
    T=read();
    // for(int i=0;i<=n;++i) dis[i]=1145141919;
    int u,v,w;
    for(int i=1;i<=m;++i){
        u=read(); v=read();
        w=read(); --w;
        addedge(u,v,w);
        addedge(v,u,w);
    }
    // dij();
    bfs();
    printf("%d\n",(ans-1)*7+1);
    return 0;
}