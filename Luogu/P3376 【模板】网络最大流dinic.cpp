#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<queue>
#include<cstring>
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
const int N=210,M=10004,inf=2147483647;
int n,m,s,t,ans,maxflow;
int dep[N],ped[N];
bool flag[N][N];
struct node{
    int to,nxt,w;
}e[M];
int idx=1,head[N],cur[N];
void addedge(int u,int v,int w){
    e[++idx].to=v;
    e[idx].w=w;
    e[idx].nxt=head[u];
    head[u]=idx;
}
bool bfs(){
    memset(dep,0,sizeof(dep));
    memset(ped,0,sizeof(ped));
    memcpy(cur,head,sizeof(head));
    dep[s]=1;
    int p;
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        p=q.front();
        q.pop();
        for(int i=head[p];i;i=e[i].nxt){
            int v=e[i].to;
            if(e[i].w<=0||dep[v]) continue;//不要重复访问
            q.push(v);
            dep[v]=dep[p]+1;
        }
    }
    return (dep[t]!=0);
}
int dfs(int x=s,int flow=inf){
    if(x==t){
        return flow;
    }
    int used=0;
    for(int &i=cur[x];i;i=e[i].nxt){
        int v=e[i].to;
        if(e[i].w>0&&dep[v]==dep[x]+1){
            //如果还有剩余的流量以及没有断层
            int c=dfs(v,min(flow-used,e[i].w));
            e[i].w-=c;
            e[i^1].w+=c;
            used+=c;
            if(used==flow) return used;
        }
    }
    return used;
}
int dinic(){
    maxflow=0;
    while(bfs()){
        maxflow+=dfs();
    }
    return maxflow;
}
signed main()
{
    n=read(); m=read();
    s=read(); t=read();
    for(int i=1;i<=m;++i){
        int u=read(),v=read(),w=read();
        addedge(u,v,w);
        addedge(v,u,0);
    }
    printf("%lld\n",dinic());
    return 0;
}