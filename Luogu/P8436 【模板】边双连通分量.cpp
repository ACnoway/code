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
const int N=2000004,M=80000006;
int n,m;
int dfid,cnt,dfn[N],low[N],fenl[N];
bool ge[M];
struct node{
    int to,nxt;
}e[M];
int idx=1,head[N];
vector<vector<int> > ans;
inline void add(int u,int v){
    e[++idx].to=v;
    e[idx].nxt=head[u];
    head[u]=idx;
}
void tarjan(int x,int dieb){
    dfn[x]=low[x]=++dfid;
    for(int i=head[x];i;i=e[i].nxt){
        int v=e[i].to;
        //如果是树边就遍历下去
        if(dfn[v]==0){
            tarjan(v,i);
            if(low[v]>=dfn[x])
                ge[i]=ge[i^1]=1;
            low[x]=min(low[x],low[v]);
        }
        //如果是回边直接更新low
        else if(i!=(dieb^1)) low[x]=min(low[x],dfn[v]);
    }
}
void dfs(int x,int fenlc){
    fenl[x]=fenlc;
    ans[fenlc-1].push_back(x);
    for(int i=head[x];i;i=e[i].nxt){
        int v=e[i].to;
        //如果在别的连通分量或者是割边就跳过
        if(fenl[v]||ge[i]) continue;
        dfs(v,fenlc);
    }
}
int main()
{
    n=read(); m=read();
    int x,y;
    for(int i=1;i<=m;++i){
        x=read(); y=read();
        if(x==y) continue;
        add(x,y); add(y,x);
    }
    for(int i=1;i<=n;++i){
        if(dfn[i]==0) tarjan(i,0);
    }
    int ac=0;
    for(int i=1;i<=n;++i){
        if(fenl[i]==0){
            ans.push_back(vector <int>());
            dfs(i,++ac);
        }
    }
    printf("%d\n",ac);
    for(int i=0;i<ac;++i){
        printf("%d",ans[i].size());
        for(int j:ans[i]) printf(" %d",j);
        putchar('\n');
    }
    return 0;
}