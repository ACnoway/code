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
const int mod=998244353;
int n,m,k,ans,sum,cnt,tmp;
int ksm(int a,int b){
    int aa=1;
    while(b){
        if(b&1) aa*=a,aa%=mod;
        a*=a;
        a%=mod;
        b>>=1;
    }
    return aa;
}
int gcd(int a,int b){
    if(!b) return a;
    return gcd(b,a%b);
}
signed main()
{
    n=read();
    m=read();
    k=read();
    int kk=1;
    for(int i=2;i<=k;++i){
        kk*=i;
        kk%=mod;
    }
    kk=ksm(kk,mod-2);
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            if(i*j>=k){
                tmp=1;
                for(int p=0;p<k;++p){
                    tmp*=(i*j-p);
                }
                cout<<i<<' '<<j<<endl;
                cnt=(n-i+1)*(m-j+1)*tmp*kk;
                cnt%=mod;
                ans+=i*j*cnt;
                ans%=mod;
                sum+=cnt;
                sum%=mod;
                cout<<ans<<' '<<sum<<endl;
            }
        }
    }
    int d=gcd(ans,sum);
    ans/=d; sum/=d;
    cout<<ans<<' '<<sum<<endl;
    sum=ksm(sum,mod-2);
    printf("%lld\n",(ans*sum)%mod);
    return 0;
}