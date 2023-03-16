#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<climits>
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
const int N=400005,M=1000006;
int n,m,s,ed,nf;
int dfid,dfn[N],low[N];
vector<int> e[N],E[N];
int top,st[N];
void tarjan(int x,int die){
    dfn[x]=low[x]=++dfid;
    st[++top]=x;
    for(int v:e[x]){
        if(!dfn[v]){
            tarjan(v,x);
            low[x]=min(low[x],low[v]);
            if(low[v]>=dfn[x]){
                //新建方点连边
                ++nf;
                E[nf].push_back(v);
                E[v].push_back(nf);
                while(st[top]!=v){
                    E[nf].push_back(st[top]);
                    E[st[top]].push_back(nf);
                    --top;
                }
                --top;
                E[x].push_back(nf);
                E[nf].push_back(x);
            }
        }
        else if(v!=die) low[x]=min(low[x],dfn[v]);
    }
}
void dfs(int x,int ans,int die){
    if(x==ed){
        if(ans==0){
            //没找到割点说明无解
            debug(x);
            printf("No solution\n");
        }
        else{
            printf("%d\n",ans);
        }
        exit(0);
    }
    //如果是割点，记录ans
    //不是起点 叶子结点        原点
    if(x!=s&&E[x].size()>1&&x<=n){
        if(ans==0) ans=x;
        else ans=min(ans,x);
    }
    for(int v:E[x]){
        if(v!=die) dfs(v,ans,x);
    }
}
int main()
{
    n=read();
    int x,y;
    do{
        x=read(); y=read();
        e[x].push_back(y);
        e[y].push_back(x);
        ++m;
    }while(x&&y);
    s=read(); ed=read();
    nf=n;
    --m;
    tarjan(s,0);
    if(!dfn[ed]){
        printf("No solution\n");
        return 0;
    }
    //以起点为根，在圆方树上跑dfs，找到终点经过的最小的割点
    dfs(s,0,0);
    return 0;
}