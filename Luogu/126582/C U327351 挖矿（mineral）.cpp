#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
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
int n,m,dfid,col,v;
long long ans;
long long f[N],sum[N];
int a[N],dfn[N],low[N],color[N],vis[N],ru[N];
int top,st[N];
int idx,head[N<<1],to[N<<1],nxt[N<<1];
void addedge(int u,int v){
    to[++idx]=v;
    nxt[idx]=head[u];
    head[u]=idx;
}
void tarjan(int x){
    dfn[x]=low[x]=++dfid;
    st[++top]=x;
    vis[x]=1;
    for(int i=head[x];i;i=nxt[i]){
        v=to[i];
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
    for(int i=head[x];i;i=nxt[i]){
        v=to[i]-n;
        if(f[x]+sum[v]>f[v]){
            f[v]=f[x]+sum[v];
            ans=max(f[v],ans);
            dfs(v+n);
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
        addedge(u,v);
    }
    for(int i=1;i<=n;++i){
        if(!dfn[i]) tarjan(i);
    }
    for(int i=1;i<=n;++i){
        for(int j=head[i];j;j=nxt[j]){
            v=to[j];
            if(color[i]!=color[v]){
                addedge(color[i]+n,color[v]+n);
                ++ru[color[v]];
            }
        }
    }
    for(int i=1;i<=col;++i){
        if(sum[i]){
            f[i]=sum[i];
            ans=max(sum[i],ans);
            dfs(i+n);
        }
    }
    printf("%lld\n",ans);
    return 0;
}