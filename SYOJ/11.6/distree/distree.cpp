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
const int N=50004,M=500005,inf=1000000001;
int n,m;
int idx,head[N],nxt[M],to[M],w[M];
int bian[N];
inline void add(int u,int v,int _w){
    to[++idx]=v;
    nxt[idx]=head[u];
    w[idx]=_w;
    head[u]=idx;
}
typedef pair<int,int> pii;
priority_queue<pii,vector<pii>,greater<pii> > q;
int dis[N];
bool vis[N],use[M];
inline void dij(int x){
    for(int i=0;i<=n;++i) dis[i]=inf;
    q.emplace((pii){0,x});
    dis[x]=0;
    pii p;
    int u,v,d;
    while(q.size()){
        p=q.top();
        q.pop();
        u=p.second,d=dis[u];
        if(vis[u]) continue;
        vis[u]=1;
        for(int i=head[u];i;i=nxt[i]){
            v=to[i];
            if(dis[v]>d+w[i]){
                dis[v]=d+w[i];
                bian[v]=i;
                if(!vis[v]) q.emplace((pii){dis[v],v});
            }
            else if(dis[v]==d+w[i])
                bian[v]=i;
        }
    }
}
int main()
{
    freopen("distree.in","r",stdin);
    freopen("distree.out","w",stdout);
    n=read();
    m=read();
    for(int i=0;i<m;++i){
        int u=read(),v=read(),_w=read();
        if(u!=v) add(u,v,_w);
    }
    dij(1);
    for(int i=1;i<=n;++i){
        use[bian[i]]=1;
    }
    long long ans=0;
    for(int i=1;i<=idx;++i) if(use[i]) ans+=(long long)w[i];
    printf("%lld\n",ans);
    return 0;
}
// %%%stO zyb Orz%%%
// %%%stO zyb Orz%%%
// %%%stO zyb Orz%%%
// %%%stO zyb Orz%%%
// %%%stO zyb Orz%%%
// %%%stO zyb Orz%%%
// %%%stO zyb Orz%%%
// %%%stO zyb Orz%%%
// %%%stO zyb Orz%%%
// %%%stO zyb Orz%%%
// %%%stO zyb Orz%%%
// %%%stO zyb Orz%%%
// %%%stO zyb Orz%%%
// %%%stO zyb Orz%%%
// %%%stO zyb Orz%%%
// %%%stO zyb Orz%%%
// %%%stO zyb Orz%%%
// %%%stO zyb Orz%%%
// %%%stO zyb Orz%%%
// %%%stO zyb Orz%%%
// %%%stO zyb Orz%%%
// %%%stO zyb Orz%%%
// %%%stO zyb Orz%%%
// %%%stO zyb Orz%%%
// %%%stO zyb Orz%%%
// %%%stO zyb Orz%%%
// %%%stO zyb Orz%%%
// %%%stO zyb Orz%%%
// %%%stO zyb Orz%%%
// %%%stO zyb Orz%%%
// %%%stO xhx Orz%%%
// %%%stO xhx Orz%%%
// %%%stO xhx Orz%%%
// %%%stO xhx Orz%%%
// %%%stO xhx Orz%%%
// %%%stO xhx Orz%%%
// %%%stO xhx Orz%%%
// %%%stO xhx Orz%%%
// %%%stO xhx Orz%%%
// %%%stO xhx Orz%%%
// %%%stO xhx Orz%%%
// %%%stO xhx Orz%%%
// %%%stO xhx Orz%%%
// %%%stO xhx Orz%%%
// %%%stO xhx Orz%%%
// %%%stO xhx Orz%%%
// %%%stO xhx Orz%%%
// %%%stO xhx Orz%%%
// %%%stO xhx Orz%%%
// %%%stO xhx Orz%%%
// %%%stO xhx Orz%%%
// %%%stO xhx Orz%%%
// %%%stO xhx Orz%%%
// %%%stO xhx Orz%%%
// %%%stO xhx Orz%%%
// %%%stO xhx Orz%%%
// %%%stO xhx Orz%%%
// %%%stO xhx Orz%%%
// %%%stO xhx Orz%%%
// %%%stO xhx Orz%%%