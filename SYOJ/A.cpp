#include<iostream>
#include<cstdio>
#define int long long
using namespace std;
const int mod=1e9+7;
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
    int n,m,ans=2;
    while(~scanf("%lld%lld",&n,&m)){
    	if(n==1){
    		printf("%lld\n",m%mod);
    		continue;
		}
		if(n&1) printf("%lld\n",(qpow(m-1,n)%mod+mod-m+1)%mod);
		else printf("%lld\n",(qpow(m-1,n)%mod+m-1)%mod);
    }
    return 0;
}
