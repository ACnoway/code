#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
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
const int N=1000006,mod=998244353;
int n,t,k;
int a[N];
signed main()
{
	n=read();
	t=read(),k=read();
	for(int i=1;i<=n;++i) a[i]=read();
	int ans=0;
	for(int i=2;i<n;++i){
		ans+=a[i]*((1ll<<(t+2))-t-3);
		ans%=mod;
	}
	ans+=a[1]*((1ll<<(t+1))-1);
	ans%=mod;
	ans+=a[n]*((1ll<<(t+1))-1);
	ans%=mod;
	printf("%lld\n",ans);
	return 0;
}
