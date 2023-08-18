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
const int N=2e5+10;
int n,m,S,T;
int idx=1,head[N<<4],to[N<<4],nxt[N<<4];
void addedge(int u,int v){
    to[++idx]=v;
    nxt[idx]=head[u];
    head[u]=idx;
}
int main()
{
    n=read();
    m=read();
    S=read();
    T=read();
    int u,v,w;
    for(int i=1;i<=m;++i){
        u=read(); v=read();
        w=read(); --w;
        u+=w*n;
        v+=w*n;
        addedge()
    }
    return 0;
}