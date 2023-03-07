#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
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
const int N=300005;
int n,m;
int cf[N];
struct Edge{
    int v,w;
};
vector<Edge> e[N];
int fa[20][N],dep[N],dis[N],val[N];
void dfs(int u,int die){
    fa[0][u]=die;
    dep[u]=dep[die]+1;
    //预处理倍增
    for(int i=1;i<=__lg(dep[u]);++i){
        fa[i][u]=fa[i-1][fa[i-1][u]];
    }
    for(auto [v,w]:e[u]){
        if(v!=die){
            val[v]=w;
            dis[v]=dis[u]+w;
            dfs(v,u);
        }
    }
}
int Lca(int u,int v){
    if(dep[u]<dep[v]) swap(u,v);
    //往上跳
    while(dep[u]>dep[v]){
        u=fa[__lg(dep[u]-dep[v])][u];
    }
    if(u==v) return u;
    for(int i=__lg(dep[u]);i>=0;--i){
        if(fa[i][u]!=fa[i][v]){
            u=fa[i][u];
            v=fa[i][v];
        }
    }
    return fa[0][u];
}
struct Path{
    int u,v,lca;
};
vector<Path> q;
void dfs1(int u){
    //回溯合并差分数组
    for(auto [v,w]:e[u]){
        if(v!=fa[0][u]){
            dfs1(v);
            cf[u]+=cf[v];
        }
    }
}
bool check(int mid){
    //mid为二分的所需时间
    int tot=0,ma=INT_MIN;
    for(int i=0;i<=n;++i) cf[i]=0;
    for(auto [u,v,lca]:q){
        if(dis[u]+dis[v]-2*dis[lca]>mid){
            ma=max(ma,dis[u]+dis[v]-2*dis[lca]);
            tot++;
            cf[u]++;
            cf[v]++;
            cf[lca]-=2;
        }
    }
    if(tot==0)
        return 1;
    dfs1(1);
    for(int i=2;i<=n;++i){
        if(cf[i]==tot&&ma-val[i]<=mid)
            return 1;
    }
    return 0;
}
int main()
{
    n=read();
    m=read();
    for(int i=1;i<n;++i){
        int u=read(),v=read(),w=read();
        e[u].push_back({v,w});
        e[v].push_back({u,w});
    }
    dfs(1,0);
    for(int i=1;i<=m;++i){
        int u=read(),v=read();
        int lca=Lca(u,v);
        q.push_back({u,v,lca});
    }
    int l=0,r=INT_MAX,mid,ans=0;
    while(l<=r){
        mid=(l+r)>>1;
        if(check(mid)){
            ans=mid;
            r=mid-1;
        }
        else l=mid+1;
    }
    printf("%d\n",ans);
    return 0;
}