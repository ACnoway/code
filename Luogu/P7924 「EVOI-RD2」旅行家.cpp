#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
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
const int N=500005,M=4000006;
int n,m,q,ans;
int a[N],u[M],v[M];

struct node{
    int to,nxt;
}e[M],E[M];
int ide=1,idE,head[N],Head[N];

int dfid,col,dfn[N],low[N],color[N],cf[N],he[N];
int top,st[N];

int dep[N],fa[N];
int f[20][N];

bool vis[M];
inline void add(int u,int v){
    e[++ide].to=v;
    e[ide].nxt=head[u];
    head[u]=ide;
}
inline void Add(int u,int v){
    E[++idE].to=v;
    E[idE].nxt=Head[u];
    Head[u]=idE;
}
void tarjan(int x){
    dfn[x]=low[x]=++dfid;
    st[++top]=x;
    for(int i=head[x];i;i=e[i].nxt){
        if(!vis[i]){
            vis[i]=vis[i^1]=1;
            int v=e[i].to;
            if(!dfn[v]){
                tarjan(v);
                low[x]=min(low[x],low[v]);
            }
            else low[x]=min(low[x],dfn[v]);
        }
    }
    if(dfn[x]==low[x]){
        he[++col]+=a[x];
        color[x]=col;
        while(st[top]!=x){
            he[col]+=a[st[top]];
            color[st[top]]=col;
            --top;
        }
        --top;
    }
}
int get(int x,int y){
    return (dep[x]<dep[y]?x:y);
}
void dfs(int x,int die){
    dep[x]=dep[die]+1;
    fa[x]=die;
    dfn[x]=++dfid;
    f[0][dfn[x]]=x;
    for(int i=Head[x];i;i=E[i].nxt){
        int v=E[i].to;
        if(v!=die){
            dfs(v,x);
        }
    }
}
int lca(int x,int y){
    x=dfn[x]; y=dfn[y];
    if(x>y) swap(x,y);
    int k=__lg(y-x+1);
    return get(f[k][x],f[k][y-(1<<k)+1]);
}
void Dfs(int x,int die){
    for(int i=Head[x];i;i=E[i].nxt){
        int v=E[i].to;
        if(v!=die){
            Dfs(v,x);
            cf[x]+=cf[v];
        }
    }
    if(cf[x]) ans+=he[x];
}
signed main()
{
    n=read(); m=read();
    for(int i=1;i<=n;++i) a[i]=read();
    for(int i=1;i<=m;++i){
        u[i]=read();
        v[i]=read();
        add(u[i],v[i]); add(v[i],u[i]);
    }
    q=read();
    for(int i=1;i<=n;++i){
        if(!dfn[i]) tarjan(i);
    }
    //缩完点重新连边建图
    for(int i=1;i<=m;++i){
        if(color[u[i]]^color[v[i]]){
            Add(color[u[i]],color[v[i]]);
            Add(color[v[i]],color[u[i]]);
        }
    }
    dfid=0;
    for(int i=0;i<N;++i) dfn[i]=0;
    dfs(color[1],0);
    for(int j=1;j<20;++j){
        for(int i=1;i+(1<<j)-1<=col;++i){
            f[j][i]=get(f[j-1][i],f[j-1][i+(1<<(j-1))]);
        }
    }
    for(int i=1;i<=q;++i){
        int x=read(),y=read();
        int rt=lca(color[x],color[y]);
        cf[color[x]]++; cf[color[y]]++;
        cf[fa[rt]]-=2;
    }
    Dfs(color[1],0);
    printf("%lld\n",ans);
    return 0;
}