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
const int N=500005,inf=1<<27;
int n,m,q;
int a[N],b[N],c[N],p[N],sum[N],f[N];
bool v[N];
int main()
{
    n=read();
    for(int i=1;i<=n;++i) a[i]=read();
    for(int i=1;i<=n;++i) b[i]=read();
    for(int i=1;i<=n;++i) c[i]=read();
    q=read();
    while(q--){
        m=read();
        if(m==0){
            printf("0\n");
            continue;
        }
        for(int i=1;i<=n;++i) v[i]=0,f[i]=inf;
        for(int i=1;i<=m;++i) p[i]=read(),v[p[i]]=1;
        ++m;
        p[m]=n+1;
        sum[1]=c[p[1]];
        for(int i=2;i<=m;++i) sum[i]=sum[i-1]+c[p[i]];
        int now=1;
        for(int i=1;i<=n;++i){
            if(v[i]){
                f[i]=min(f[i],min(a[i]+sum[now],f[i-1]));
                ++now;
            }
            else f[i]=min(f[i],min(a[i]+sum[now-1],f[i-1]+b[i]));
        }
        printf("%d\n",f[n]);
    }
    return 0;
}