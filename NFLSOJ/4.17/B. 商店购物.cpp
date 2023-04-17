#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
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
const int N=10000007,mod=1e9+7;
int n,m,k,tot,ans;
int a[302],jc[N],jcinv[N],f[2][N];
int ksm(int a,int b){
    int res=1;
    while(b){
        if(b&1) res*=a,res%=mod;
        a*=a;
        a%=mod;
        b>>=1;
    }
    return res;
}
int C(int n,int m){
    if(n<m) return 0;
    return jc[n]*jcinv[m]%mod*jcinv[n-m]%mod;
}
signed main()
{
    freopen("shopping.in","r",stdin);
    freopen("shopping.out","w",stdout);
    n=read(); m=read();
    k=read();
    for(int i=1;i<=m;++i) a[i]=read();
    jc[0]=1;
    for(int i=1;i<N;++i) jc[i]=jc[i-1]%mod*i%mod;
    jcinv[N-1]=ksm(jc[N-1],mod-2);
    for(int i=N-1;i;--i) jcinv[i-1]=jcinv[i]%mod*i%mod;
    f[0][0]=1;
    n-=m;
    int now=0,sum=0;
    for(int i=1;i<=m;++i){
        tot+=a[i];
        sum=0;
        for(int j=0;j<=tot;++j){
            sum+=f[now][j];
            sum%=mod;
            if(j>a[i]){
                sum-=f[now][j-a[i]-1];
                sum=(sum%mod+mod)%mod;
            }
            sum=(sum+mod)%mod;
            f[now^1][j]=sum;
        }
        now^=1;
    }
    if(!n){
        if(k<=tot) ans=f[now][k];
    }
    else{
        for(int i=min(k,tot);i>=0;--i){
            ans+=f[now][i]*C(k-i+n-1,k-i)%mod;
            ans%=mod;
        }
    }
    printf("%lld\n",ans%mod);
    return 0;
}