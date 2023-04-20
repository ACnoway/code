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
const int N=2000003;
int n,m;
int a[N];
char ans[N];
//* -----并查集
int p[N],val[N];
int find(int x){
    if(p[x]!=x){
        int tmp=p[x];
        p[x]=find(p[x]);
        val[x]+=val[tmp];
    }
    return p[x];
}
void merge(int x,int y){
    p[find(x)]=find(y);
}
signed main()
{
    n=read(); m=read();
    for(int i=1;i<=n;++i) p[i]=i,val[i]=0;
    while(m--){
        int u=read(),v=read(),w=read(),uu=find(u),vv=find(v);
        if(uu==vv){
            if(val[u]-val[v]!=w) putchar('W');
            else putchar('R');
            continue;
        }
        p[uu]=vv;
        val[uu]=val[v]-val[u]+w;
        putchar('R');
    }
    return 0;
}