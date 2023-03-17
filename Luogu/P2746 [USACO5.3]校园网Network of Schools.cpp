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
const int N=204;
int n,m,dfid,col;
int dfn[N],low[N],color[N],vis[N],ru[N],chu[N];
int top,st[N];
vector<int> e[N];
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
        while(st[top]!=x){
            color[st[top]]=col;
            vis[st[top]]=0;
            --top;
        }
        --top;
    }
}
int main()
{
    n=read();
    for(int i=1;i<=n;++i){
        int x;
        x=read();
        while(x){
            e[i].push_back(x);
            x=read();
        }
    }
    for(int i=1;i<=n;++i){
        if(!dfn[i]) tarjan(i);
    }
    for(int i=1;i<=n;++i){
        for(auto v:e[i]){
            if(color[i]!=color[v]){
                ++ru[color[v]];
                ++chu[color[i]];
            }
        }
    }
    int a1=0,a2=0;
    for(int i=1;i<=col;++i){
        if(!chu[i]) a1++;
        if(!ru[i]) a2++;
    }
    printf("%d\n%d\n",a2,(col==1?0:max(a1,a2)));
    return 0;
}