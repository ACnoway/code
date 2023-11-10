#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
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
const int N=200005,M=1000006,inf=1<<27,mod=998244353;
int n,m,h,t;
int idx=1,head[N],nxt[M],to[M];
inline void add(int u,int v){
    to[++idx]=v;
    nxt[idx]=head[u];
    head[u]=idx;
}
int dis[2][N],cnt[2][N],vis[N];
typedef pair<int,int> pii;
typedef pair<pii,int> piii;
piii q[N<<2];
void bfs(int x){
    piii p;
    q[++t]={{0,x},0};
    vis[x]=1;
    dis[0][x]=0;
    cnt[0][x]=1;
    int u,k,d,v;
    while(h<t){
        p=q[++h];
        u=p.first.second,d=p.first.first+1;
        k=p.second;
        for(int i=head[u];i;i=nxt[i]){
            v=to[i];
            if(!vis[v]){
                // shortest
                vis[v]=1;
                q[++t]={{d,v},0};
                dis[0][v]=d;
                cnt[0][v]=cnt[k][u];
            }
            else if(d==dis[0][v]) cnt[0][v]+=cnt[k][u],cnt[0][v]%=mod;
            else if(vis[v]==1){
                // second
                vis[v]=2;
                q[++t]={{d,v},1};
                dis[1][v]=d;
                cnt[1][v]=cnt[k][u];
            }
            else if(d==dis[1][v]) cnt[1][v]+=cnt[k][u],cnt[1][v]%=mod;
        }
    }
}
int main()
{
    freopen("path.in","r",stdin);
    freopen("path.out","w",stdout);
    n=read();
    m=read();
    for(int i=1;i<=n;++i) dis[0][i]=dis[1][i]=inf;
    for(int i=1;i<=m;++i){
        int u=read(),v=read();
        add(u,v);
        add(v,u);
    }
    bfs(1);
    printf("%d\n",(dis[1][n]==dis[0][n]+1?cnt[1][n]:0));
    return 0;
}