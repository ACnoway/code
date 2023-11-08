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
// const int N=200005;
// int n,m,cnt;
// int idx=1,head[N],nxt[N<<1],to[N<<1];
// inline void add(int u,int v){
//     to[++idx]=v;
//     nxt[idx]=head[u];
//     head[u]=idx;
// }
// int pt[N];
// void dfs(int x,int die){
//     for(int i=head[x];i;i=nxt[i]){
//         if(to[i]!=die){
//             dfs(to[i],x);
//         }
//     }
//     pt[++cnt]=x;
// }
int main()
{
    freopen("transport.in","r",stdin);
    freopen("transport.out","w",stdout);
    // n=read();
    // m=read();
    // for(int i=1;i<n;++i){
    //     int u=read(),v=read();
    //     add(u,v);
    //     add(v,u);
    // }
    // dfs(1,0);
    return 0;
}