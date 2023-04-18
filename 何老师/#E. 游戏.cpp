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
const int N=210,M=20004,inf=2147483647;
int n,m,s,t,ans,maxflow;
int a[N],b[N];
int dep[N],ped[N];
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
void bfs(){
    memset(dep,-1,sizeof(dep));
    memset(ped,0,sizeof(ped));
    dep[t]=0;
    ped[0]=1;
    queue<int> q;
    int p;
    q.push(t);
    while(!q.empty()){
        p=q.front();
        q.pop();
        for(int i=head[p];i;i=e[i].nxt){
            int v=e[i].to;
            if(dep[v]!=-1) continue;
            q.push(v);
            dep[v]=dep[p]+1;
            ++ped[dep[v]];
        }
    }
    return;
}
int dfs(int x,int flow){
    if(x==t){
        maxflow+=flow;
        return flow;
    }
    int used=0;
    for(int &i=cur[x];i;i=e[i].nxt){
        int v=e[i].to;
        if(e[i].w&&dep[v]+1==dep[x]){
            int c=dfs(v,min(flow-used,e[i].w));
            if(c){
                e[i].w-=c;
                e[i^1].w+=c;
                used+=c;
            }
            if(used==flow) return used;
        }
    }
    if(--ped[dep[x]]==0) dep[s]=N-1;
    ++dep[x];
    ++ped[dep[x]];
    return used;
}
int ISAP(){
    maxflow=0;
    bfs();
    while(dep[s]<t){
        memcpy(cur,head,sizeof(head));
        dfs(s,inf);
    }
    return maxflow;
}
signed main()
{
    n=read(); m=read();
    s=0; t=n+n+1;
    for(int i=1;i<=n;++i){
        a[i]=read();
        addedge(s,i,a[i]);
        addedge(i,s,0);
    }
    for(int i=1;i<=n;++i){
        b[i]=read();
        addedge(i+n,t,b[i]);
        addedge(t,i+n,0);
    }
    for(int i=1;i<=m;++i){
        int u=read(),v=read();
        v+=n;
        addedge(u,v,inf);
        addedge(v,u,0);
    }
    printf("%lld\n",ISAP());
    return 0;
}