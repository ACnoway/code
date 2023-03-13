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
const int N=2000006;
int n,x,y;
int peiu[N],peiv[N],color[N];
struct node{
    int to,nxt;
}e[N];
int idx,head[N];
inline void add(int u,int v){
    e[++idx].to=v;
    e[idx].nxt=head[u];
    head[u]=idx;
}
void dfs(int x,int c){
    color[x]=c;
    for(int i=head[x];i;i=e[i].nxt){
        if(color[e[i].to]==-1)
            dfs(e[i].to,c^1);
    }
}
int main()
{
    n=read();
    for(int i=1;i<=n;++i){
        color[i]=-1;
        x=read();
        y=read();
        if(peiu[x]){
            add(peiu[x],i);
            add(i,peiu[x]);
            peiu[x]=0;
        }
        else peiu[x]=i;
        if(peiv[y]){
            add(peiv[y],i);
            add(i,peiv[y]);
            peiv[y]=0;
        }
        else peiv[y]=i;
    }
    for(int i=1;i<=n;++i){
        if(color[i]==-1){
            dfs(i,0);
        }
    }
    for(int i=1;i<=n;++i){
        putchar("br"[color[i]]);
    }
    return 0;
}