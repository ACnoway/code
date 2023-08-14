#include<iostream>
#include<cmath>
#include<cstdio>
#define int long long
using namespace std;
const int N=1003,mod=1e9+7;
int n,nn,invn;
int a[N][N];
int b[35];
int qpow(int a,int b){
	int res=1;
	while(b){
		if(b&1ll) res*=a,res%=mod;
		a*=a,a%=mod;
		b>>=1ll;
	}
	return res;
}
signed main()
{
	cin>>n;
	nn=qpow(n,n);
	invn=qpow(nn,mod-2ll);
	int tmp=0ll;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			cin>>a[i][j];
			tmp=max(tmp,a[i][j]);
		}
	}
	int maxwei=0ll,cnt=0ll;
	while(tmp){
		++maxwei;
		tmp>>=1ll;
	}
	for(int k=0;k<maxwei;++k){
		b[k]=1;
		for(int i=1;i<=n;++i){
			cnt=0;
			for(int j=1;j<=n;++j){
				if(!((a[i][j]>>k)&1ll)) ++cnt;
			}
			b[k]*=cnt;
			b[k]%=mod;
		}
	}
	int ans=0;
	for(int i=0;i<maxwei;++i){
		ans+=(nn+mod-b[i])%mod*invn%mod*(1ll<<i)%mod;
		ans%=mod;
	}
	cout<<ans<<endl;
	return 0;
}