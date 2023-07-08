#include<iostream>
#include<cstdio>
#define int long long
using namespace std;
const int N=1000000,mod=1e9+7;
int jc[N+10],inv[N+10],f[N+10];
int read(){
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
int qpow(int a,int b){
	int res=1;
	while(b){
		if(b&1) res*=a,res%=mod;
		a*=a,a%=mod;
		b>>=1;
	}
	return res;
}
void init(){
	jc[0]=1;
	for(int i=1;i<=N;++i){
		jc[i]=jc[i-1]*i%mod;
	}
	inv[N]=qpow(jc[N],mod-2);
	for(int i=N-1;i>=0;--i){
		inv[i]=inv[i+1]*(i+1)%mod;
	}
	f[0]=1; f[1]=0; f[2]=1;
	for(int i=3;i<=N;++i){
		f[i]=(i-1)*(f[i-1]+f[i-2])%mod;
	}
}
int C(int n,int m){
	return jc[n]*inv[m]%mod*inv[n-m]%mod;
}
signed main()
{
	init();
	int T,n,m,ans;
	T=read();
	while(T--){
		n=read(); m=read();
		ans=C(n,m);
		n-=m;
		ans*=f[n], ans%=mod;
		printf("%lld\n",ans);
	}
	return 0;
}
