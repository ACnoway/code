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
const int N=500005;
int n,m;
vector<int> e[N];
int dfid,dfn[N],hui[N],low[N],dep[N];
int fa[N][21];
void tarjan(int x,int die){
    dep[x]=dep[die]+1;
    fa[x][0]=die;
    int k=__lg(dep[x])+1;
    for(int i=1;i<=k;++i) fa[x][i]=fa[fa[x][i-1]][i-1];
    dfn[x]=low[x]=++dfid;
    for(int v:e[x]){
        if(!dfn[v]){
            tarjan(v,x);
            low[x]=min(low[x],low[v]);
        }
        else if(v!=die) low[x]=min(low[x],dfn[v]);
    }
    hui[x]=++dfid;
}
int lca(int x,int y){
    if(dep[x]<dep[y]) swap(x,y);
    while(dep[x]>dep[y]) x=fa[x][__lg(dep[x]-dep[y])];
    if(x==y) return x;
    for(int i=__lg(dep[x])+1;i>=0;--i){
        if(fa[x][i]!=fa[y][i]){
            x=fa[x][i];
            y=fa[y][i];
        }
    }
    return fa[x][0];
}
bool baohan(int x,int y){
    return dfn[x]<=dfn[y]&&hui[x]>=hui[y];
}
int xiayige(int x,int y){
    //找x与y的路径中x的下一个点
    int dx=dep[x]+1;
    while(dep[y]>dx) y=fa[y][__lg(dep[y]-dx)];
    return y;
}
bool query1(int a,int b,int g1,int g2){
    if(a==b) return 1;
    if(dfn[a]>dfn[b]) swap(a,b);
    if(dfn[g1]>dfn[g2]) swap(g1,g2);
    if(dep[g2]!=dep[g1]+1) return 1;//g1到g2是回边
    debug(a);
    if(baohan(a,b)){
        if(baohan(a,g1)&&baohan(g2,b)){
            return low[g2]<=dfn[g1];//判割边
        }
        else return 1;
    }
    else{
        int rt=lca(a,b);
        return query1(a,rt,g1,g2)&&query1(b,rt,g1,g2);
    }
}
bool query2(int a,int b,int c){
    if(a==b) return a!=c;
    if(a==c||b==c) return 0;
    if(dfn[a]>dfn[b]) swap(a,b);
    if(baohan(a,b)){
        if(baohan(a,c)&&baohan(c,b)){
            //找割点
            return low[xiayige(c,b)]<dfn[c];
        }
        else return 1;
    }
    else{
        int rt=lca(a,b);
        if(baohan(rt,c)&&(baohan(c,a)||baohan(c,b))){
            return query2(a,fa[rt][0],c)&&query2(b,fa[rt][0],c);
        }
        else return 1;
    }
}
signed main()
{
    n=read(); m=read();
    for(int i=1;i<=m;++i){
        int x=read(),y=read();
        e[x].push_back(y);
        e[y].push_back(x);
    }
    tarjan(1,1);
    int q,a,b,x,y;
    q=read();
    for(int i=1;i<=q;++i){
        a=read();
        if(a==1){
            a=read(); b=read();
            x=read(); y=read();
            printf((query1(a,b,x,y)?"yes\n":"no\n"));
        }
        else{
            a=read(); b=read();
            x=read();
            printf((query2(a,b,x)?"yes\n":"no\n"));
        }
    }
    return 0;
}