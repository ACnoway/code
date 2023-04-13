#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
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
const int N=200002,inf=2147483647;
int n,m,s,t,ans,maxflow;
int dep[N],ped[N];
struct node{
    int to,nxt,w;
}e[N];
int idx=1,head[N],cur[N];
void addedge(int u,int v,int w){
    e[++idx].to=v;
    e[idx].nxt=head[u];
    e[idx].w=w;
    head[u]=idx;
}
void bfs(){
    for(int i=0;i<=n+1;++i){
        dep[i]=-1;
        ped[i]=0;
    }
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
            dep[v]=dep[i]+1;
            q.push(v);
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
            if(used==flow) return flow;
        }
    }
    if(--ped[dep[x]]==0) dep[s]=n+2;
    ++dep[x];
    ++ped[dep[x]];
    return used;
}
void isap(){
    maxflow=0;
    bfs();
    while(dep[s]<=n){
        for(int i=0;i<=n+1;++i) cur[i]=head[i];
        dfs(s,inf);
    }
}
signed main()
{
    m=read(); n=read();
    s=0; t=n+1;
    int u=read(),v=read();
    while(u!=-1){
        addedge(u,v,inf);
        addedge(v,u,0);
        u=read(); v=read();
    }
    for(int i=1;i<=m;++i){
        addedge(s,i,1);
        addedge(i,s,0);
    }
    for(int i=m+1;i<=n;++i){
        addedge(i,t,1);
        addedge(t,i,0);
    }
    isap();
    if(!maxflow){
        printf("No Solution!\n");
        return 0;
    }
    printf("%lld\n",maxflow);
    for(int i=2;i<=idx;i+=2){
        //判断这条边的两边是否为源点或汇点，且反边边权不为0，即为最大流中使用了的一组
        if(e[i].to!=s&&e[i^1].to!=s&&e[i].to!=t&&e[i^1].to!=t&&e[i^1].w){
            printf("%lld %lld\n",e[i^1].to,e[i].to);
        }
    }
    return 0;
}