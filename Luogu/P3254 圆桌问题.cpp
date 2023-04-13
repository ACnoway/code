#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
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
const int N=502,inf=2147483647;
int n,m,s,t,ans,maxflow;
int a[N],dep[N],ped[N];
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
            dep[v]=dep[i]+1;
            q.push(v);
            ++ped[dep[v]];
        }
    }
    return;
}
int dfs(int x,int flow){
    if(x==t){
        maxflow-=flow;
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
    if(--ped[dep[x]]==0) dep[s]=N-1;
    ++dep[x];
    ++ped[dep[x]];
    return used;
}
void isap(){
    bfs();
    while(dep[s]<n+m+2){
        for(int i=0;i<=t;++i) cur[i]=head[i];
        dfs(s,inf);
    }
}
signed main()
{
    n=read(); m=read();
    s=0; t=n+m+1;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            addedge(i,j+n,1);
            addedge(j+n,i,0);
        }
    }
    for(int i=1;i<=n;++i){
        int x=read();
        maxflow+=x;
        addedge(s,i,x);
        addedge(i,s,0);
    }
    for(int i=1;i<=m;++i){
        int x=read();
        addedge(i+n,t,x);
        addedge(t,i+n,0);
    }
    isap();
    if(maxflow==0){
        printf("1\n");
        for(int i=1;i<=n;++i){
            debug(i);
            for(int j=head[i];j;j=e[j].nxt){
                int v=e[j].to;
                debug(v);
                if(v!=s&&e[j].w){
                    printf("%lld ",v-n);
                }
            }
            putchar('\n');
        }
    }
    else printf("0\n");
    return 0;
}