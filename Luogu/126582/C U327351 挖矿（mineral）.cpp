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
const int N=1000006;
int n,m,dfid,col;
long long ans;
long long f[N],sum[N];
int a[N],dfn[N],low[N],color[N],vis[N],ru[N];
int top,st[N];
vector<int> e[N],E[N];
void tarjan(int x){
    dfn[x]=low[x]=++dfid;
    st[++top]=x;
    vis[x]=1;
    for(int v:e[x]){
        if(!dfn[v]){
            tarjan(v);
            low[x]=min(low[x],low[v]);
        }
        else if(vis[v]==1) low[x]=min(low[x],dfn[v]);
    }
    if(dfn[x]==low[x]){
        color[x]=++col;
        vis[x]=0;
        sum[col]=a[x];
        while(st[top]!=x){
            color[st[top]]=col;
            sum[col]+=a[st[top]];
            vis[st[top]]=0;
            --top;
        }
        --top;
    }
}
void dfs(int x){
    for(auto v:E[x]){
        if(f[x]+sum[v]>f[v]){
            f[v]=f[x]+sum[v];
            ans=max(f[v],ans);
            dfs(v);
        }
    }
}
int main()
{
    n=read();
    m=read();
    for(int i=1;i<=n;++i) a[i]=read();
    for(int i=1;i<=m;++i){
        int u=read(),v=read();
        e[u].push_back(v);
    }
    for(int i=1;i<=n;++i){
        if(!dfn[i]) tarjan(i);
    }
    for(int i=1;i<=n;++i){
        for(auto v:e[i]){
            if(color[i]!=color[v]){
                E[color[i]].push_back(color[v]);
                ++ru[color[v]];
            }
        }
    }
    for(int i=1;i<=col;++i){
        if(sum[i]){
            f[i]=sum[i];
            ans=max(sum[i],ans);
            dfs(i);
        }
    }
    printf("%lld\n",ans);
    return 0;
}