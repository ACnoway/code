#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
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
const int N=50004,M=100004;
int n,m;
struct node{
    int to,nxt;
}e[M];
int idx=1,head[N];
int top,st[N];
int cnt,dfid,col,color[N],du[N],dfn[N],low[N],u[M],v[M];
bool ge[M],vis[N];
inline void add(int u,int v){
    e[++idx].to=v;
    e[idx].nxt=head[u];
    head[u]=idx;
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
    if(low[x]==dfn[x]){
        color[x]=++col;
        while(st[top]!=x){
            color[st[top]]=col;
            --top;
        }
        --top;
    }
}
int main()
{
    n=read();
    m=read();
    for(int i=1;i<=m;++i){
        u[i]=read();
        v[i]=read();
        add(u[i],v[i]);
        add(v[i],u[i]);
    }
    for(int i=1;i<=n;++i){
        if(!dfn[i]) tarjan(i);
    }
    for(int i=1;i<=m;++i){
        if(color[u[i]]!=color[v[i]]){
            ++du[color[u[i]]];
            ++du[color[v[i]]];
        }
    }
    int ans=0;
    for(int i=1;i<=col;++i){
        if(du[i]==1) ans++;
    }
    printf("%d\n",ans+1>>1);
    return 0;
}