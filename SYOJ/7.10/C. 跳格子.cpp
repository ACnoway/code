#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#define int long long
#ifdef ONLINE_JUDGE
#define debug(x)
#else
#define debug(x) cout<<' '<<#x<<'='<<x<<endl;
#endif
using namespace std;
const int mod=1e9+7;
int n;
int inv[10000007];
int qpow(int a,int b){
    int res=1;
    while(b){
        if(b&1) res*=a,res%=mod;
        a*=a,a%=mod;
        b>>=1;
    }
    return res;
}
signed main()
{
    cin>>n;
    inv[1]=1;
    for(int i=2;i<=n;++i) inv[i]=(mod-mod/i)*inv[mod%i]%mod;
    int a=0,b=0;
    for(int i=n-1;i;--i){
        a=(b+n-i+1ll)%mod*inv[n-i]%mod;
        b=(a+b)%mod;
    }
    cout<<a%mod;
    return 0;
}