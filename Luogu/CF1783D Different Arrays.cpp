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
const int N=303,M=N*N,mod=998244353;
int n;
int a[N];
//f[i][j]表示第i次操作后第i+1个数的值为j的方案数
int f[N][(M<<1)+N];
int main()
{
    n=read();
    for(int i=1;i<=n;++i){
        a[i]=read();
    }
    f[0][a[2]+M]=1;
    for(int i=0;i<n-2;++i){
        for(int j=-M;j<=M;++j){
            if(!f[i][j+M]) continue;
            f[i+1][a[i+3]+j+M]=(f[i+1][a[i+3]+j+M]+f[i][j+M])%mod;
            if(j) f[i+1][a[i+3]-j+M]=(f[i+1][a[i+3]-j+M]+f[i][j+M])%mod;
        }
    }
    int ans=0;
    for(int i=-M;i<=M;++i) ans=(ans+f[n-2][i+M])%mod;
    printf("%d\n",ans);
    return 0;
}