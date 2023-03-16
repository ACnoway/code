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
const int N=200005,M=400005;
int n,m,nf,cnt;
long long ans;
int dfid,dfn[N],low[N],a[N],siz[N];
int top,st[N];
vector<int> e[N],E[N];
void tarjan(int x,int die){
    dfn[x]=low[x]=++dfid;
    st[++top]=x;
    //存原点，记录这个连通分量里的节点个数
    a[x]=-1; cnt++;
    for(int v:e[x]){
        if(!dfn[v]){
            tarjan(v,x);
            low[x]=min(low[x],low[v]);
            if(low[v]>=dfn[x]){
                ++nf;
                E[nf].push_back(v);
                E[v].push_back(nf);
                //记录这个连通分量的权值
                a[nf]++;
                while(st[top]!=v){
                    E[nf].push_back(st[top]);
                    E[st[top]].push_back(nf);
                    a[nf]++;
                    --top;
                }
                --top;
                E[x].push_back(nf);
                E[nf].push_back(x);
                a[nf]++;
            }
        }
        else if(v!=die) low[x]=min(low[x],dfn[v]);
    }
}
void dfs(int x,int die){
    if(a[x]==-1) siz[x]=1;
    for(int v:E[x]){
        if(v==die) continue;
        dfs(v,x);
        //直接计算两个节点的贡献
        ans+=2ll*siz[x]*siz[v]*a[x];
        //记录与这个节点相连的节点个数
        siz[x]+=siz[v];
    }
    //最后算一下这个点和它所在的连通分量里其他点的贡献
    ans+=2ll*siz[x]*(cnt-siz[x])*a[x];
}
int main()
{
    n=read(); m=read();
    for(int i=1;i<=m;++i){
        int u=read(),v=read();
        e[u].push_back(v);
        e[v].push_back(u);
    }
    nf=n;
    //这次要枚举每个点找方案数
    for(int i=1;i<=n;++i){
        cnt=0;
        if(!dfn[i]){
            tarjan(i,0);
            dfs(i,0);
        }
    }
    printf("%lld\n",ans);
    return 0;
}