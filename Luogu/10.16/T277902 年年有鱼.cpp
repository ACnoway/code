#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
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
const int N=400005;
int n,m,ma,b;
int a[N];
long long sum[N],cnt[N];
int main()
{
	n=read();
	m=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
		++cnt[a[i]];
		ma=max(ma,a[i]);
	}
	for(int i=ma;i;--i){
		sum[i]=i*cnt[i]+sum[i+1];
		cnt[i]+=cnt[i+1];
	}
	while(m--){
		b=read();
		long long ans=0;
		for(int j=b;j<=ma;j+=b){
			ans+=sum[j]-sum[j+b]-(cnt[j]-cnt[j+b])*(long long)j;
		}
		printf("%lld\n",ans+sum[1]-sum[b]);
	}
	return 0;
}
