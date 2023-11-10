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
const int N=100005,M=200005;
int n,m,ma;
struct edge{
    int u,v,w;
}e[M];
int main()
{
    freopen("maimai.in","r",stdin);
    freopen("maimai.out","w",stdout);
    n=read();
    m=read();
    for(int i=1;i<=m;++i){
        e[i].u=read(),e[i].v=read(),e[i].w=read();
        ma=max(ma,e[i].w);
    }
    printf("%d\n",ma);
    return 0;
}