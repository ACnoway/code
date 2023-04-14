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
const int N=2e5+10,mod=1000000007;
int n;
int a[N],jc[N<<1];
int ksm(int a,int b){
    int ans=1;
    while(b){
        if(b&1) ans*=a,ans%=mod;
        a*=a;
        a%=mod;
        b>>=1;
    }
    return ans;
}
int C(int n,int m){
    if(n<m) return 0;
    return jc[n]*ksm(jc[m],mod-2)%mod*ksm(jc[n-m],mod-2)%mod;
}
signed main()
{
    n=read();
    jc[0]=1;
    for(int i=1;i<N*2;++i){
        jc[i]=jc[i-1]*i%mod;
    }
    for(int i=0;i<=n;++i) a[i]=read();
    int ans=0;
    for(int i=0;i<=n;++i){
        ans+=C(i+a[i],i+1);
        ans%=mod;
    }
    printf("%lld\n",ans);
    return 0;
}