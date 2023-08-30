#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
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
const int N=300,inf=INT_MAX>>1;
int n,m,q;
typedef pair<int,int> pii;
pii a[N];
int d[N][N],f[N][N];
int main()
{
    n=read();
    m=read();
    q=read();
    for(int i=1;i<=n;++i) a[i].first=read(),a[i].second=i;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            f[i][j]=inf;
            d[i][j]=inf;
        }
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=m;++i){
        int u=read(),v=read(),w=read();
        d[u][v]=min(d[u][v],w);
        d[v][u]=min(d[v][u],w);
    }
    int x,y,z;
    for(int k=1;k<=n;++k)
        for(int i=1;i<=n;++i)
            for(int j=1;j<=n;++j){
                x=a[i].second,y=a[j].second,z=a[k].second;
                d[x][y]=min(d[x][y],d[x][z]+d[z][y]);
                f[x][y]=min(f[x][y],d[x][y]+max(a[i].first,max(a[j].first,a[k].first)));
            }
    while(q--){
        x=read(),y=read();
        printf("%d\n",f[x][y]);
    }
    return 0;
}