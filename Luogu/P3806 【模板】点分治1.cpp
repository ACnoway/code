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
const int N=10004,M=102,INF=10000007;
typedef pair<int,int> pii;
int n,m,sum,rt,a;
int query[M];
int son[N],siz[N],dis[N],rem[N],q[N];
bool vis[N],ans[INF],you[INF];
vector<pii> e[N];
void getrt(int x,int die){
    //* 找点分治要用的每颗子树的根
    siz[x]=1;
    son[x]=0;
    for(auto i:e[x]){
        int v=i.first;
        if(v==die||vis[v]) continue;
        getrt(v,x);
        siz[x]+=siz[v];
        son[x]=max(son[x],siz[v]);
    }
    son[x]=max(son[x],sum-siz[x]);
    //* 找子树大小最小的当根
    if(son[x]<son[rt]) rt=x;
}
void getdis(int x,int die){
    rem[++rem[0]]=dis[x];
    for(auto i:e[x]){
        int v=i.first,w=i.second;
        if(v==die||vis[v]) continue;
        dis[v]=dis[x]+w;
        getdis(v,x);
    }
}
void calc(int x){
    int p=0;
    for(auto i:e[x]){
        int v=i.first,w=i.second;
        if(vis[v]) continue;
        rem[0]=0;
        dis[v]=w;
        getdis(v,x);
        for(int j=rem[0];j;--j){
            for(int k=1;k<=m;++k){
                if(query[k]>=rem[j]){
                    ans[k]|=you[query[k]-rem[j]];
                }
            }
        }
        for(int j=rem[0];j;--j){
            q[++p]=rem[j];
            you[rem[j]]=1;
        }
    }
    for(int i=1;i<=p;++i){
        you[q[i]]=0;
    }
}
void solve(int x){
    //* you[i]表示到根节点距离为i的路径是否存在
    vis[x]=you[0]=1;
    calc(x);//处理以x为根的子树
    for(auto i:e[x]){
        int v=i.first;
        if(vis[v]) continue;
        sum=siz[v];
        son[rt=0]=INF;
        getrt(v,0);
        solve(rt);
    }
}
int main()
{
    n=read(); m=read();
    for(int i=1;i<n;++i){
        int u=read(),v=read(),w=read();
        e[u].push_back({v,w});
        e[v].push_back({u,w});
    }
    for(int i=1;i<=m;++i) query[i]=read();
    son[rt]=sum=n;
    getrt(1,0);
    solve(rt);
    for(int i=1;i<=m;++i){
        if(ans[i]) printf("AYE\n");
        else printf("NAY\n");
    }
    return 0;
}