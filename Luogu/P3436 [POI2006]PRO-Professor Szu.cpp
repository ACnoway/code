#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<queue>
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
const int N=1000006,M=2000006;
int n,m;
struct node{
    int to,nxt;
}e[M],E[M];
int idx,h[N],Idx,H[N];
int dfid,col,dfn[N],low[N],color[N],siz[N],ru[N],f[N];
bool huan[N];
int top,st[N];
void add(int u,int v){
    e[++idx].to=v;
    e[idx].nxt=h[u];
    h[u]=idx;
}
void Add(int u,int v){
    E[++Idx].to=v;
    E[Idx].nxt=H[u];
    H[u]=Idx;
}
void tarjan(int x){
    bool flag=0;
    dfn[x]=low[x]=++dfid;
    st[++top]=x;
    for(int i=h[x];i;i=e[i].nxt){
        int v=e[i].to;
        if(x==v) flag=1;
        if(!dfn[v]){
            tarjan(v);
            low[x]=min(low[x],low[v]);
        }
        else if(!color[v]){
            low[x]=min(low[x],dfn[v]);
        }
    }
    if(dfn[x]==low[x]){
        color[x]=++col;
        siz[col]=1;
        //判断这个连通块内是否有环
        if(flag||st[top]!=x) huan[col]=1;
        while(st[top]!=x){
            color[st[top]]=col;
            ++siz[col];
            --top;
        }
        --top;
    }
}
void tuopu(){
    queue<int> q;
    //终点的路径数自然为1
    f[color[n]]=1;
    for(int i=1;i<=col;++i){
        //拓扑找没入度的入队
        if(!ru[i]) q.push(i);
    }
    int p,v;
    while(!q.empty()){
        p=q.front();
        q.pop();
        //如果进到终点所在的块里面就不用继续往下找了
        if(p==color[n]) continue;
        for(int i=H[p];i;i=E[i].nxt){
            v=E[i].to;
            --ru[v];
            if(!ru[v]) q.push(v);
        }
    }
    //要把终点留在队列里
    q.push(color[n]);
    while(!q.empty()){
        p=q.front();
        q.pop();
        if(huan[p]&&f[p]) f[p]=36501;//有环就给最大值
        for(int i=H[p];i;i=E[i].nxt){
            v=E[i].to;
            f[v]=min(f[v]+f[p],36501);
            --ru[v];
            if(!ru[v]) q.push(v);
        }
    }
}
int main()
{
    n=read();
    m=read();
    ++n;
    for(int i=0;i<m;++i){
        int u=read(),v=read();
        add(v,u);
    }
    for(int i=1;i<=n;++i){
        if(!dfn[i]){
            tarjan(i);
        }
    }
    for(int i=1;i<=n;++i){
        for(int j=h[i];j;j=e[j].nxt){
            if(color[i]!=color[e[j].to]){
                Add(color[i],color[e[j].to]);
                ++ru[color[e[j].to]];
            }
        }
    }
    tuopu();
    int ans=0,res=0;
    for(int i=1;i<=col;++i) ans=max(ans,f[i]);
    if(ans==36501) printf("zawsze\n");
    else printf("%d\n",ans);
    if(ans==f[color[n]]){
        //如果答案包含终点的话记录res的时候需要减一
        --res;
    }
    for(int i=1;i<=col;++i)
        if(ans==f[i]) res+=siz[i];
    printf("%d\n",res);
    for(int i=1;i<n;++i)
        if(ans==f[color[i]]) printf("%d ",i);
    putchar('\n');
    return 0;
}