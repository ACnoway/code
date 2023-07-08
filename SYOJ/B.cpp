#include<iostream>
#include<cstdio>
#define int long long
using namespace std;
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
const int N=1000000,mod=1000003;
int T,n,a,b;
int jc[N+10],inv[N+10];
int qpow(int a,int b){
	int res=1;
	while(b){
		if(b&1) res*=a,res%=mod;
		a*=a,a%=mod;
		b>>=1;
	} 
	return res;
}
int init(){
	jc[0]=1;
	for (int i=1;i<=N;++i){
		jc[i]=jc[i-1]*i%mod;
	}
	inv[N]=qpow(jc[N],mod-2);
	for(int i=N-1;i>=0;--i){
		inv[i]=(i+1)*inv[i+1]%mod;
	}
}
int lucas(int n,int m){
	if(m>n) return 0;
	if(n>N||m>N) return lucas(n/mod,m/mod)*lucas(n%mod,m%mod)%mod;
	return jc[n]*inv[m]%mod*inv[n-m]%mod;
}
signed main()
{
	init();
	T=read();
	while(T--){
		n=read(); a=read(); b=read();
		cout<<(lucas(b-a+1+n,b-a+1)+mod-1)%mod<<endl;
	}
	return 0;
}
