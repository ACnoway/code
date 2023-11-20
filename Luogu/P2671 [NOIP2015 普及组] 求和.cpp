#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
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
const int N=100005,mod=10007;
int n,m;
int v[N],b[N],f[N][2],c[N][2];
int main()
{
	n=read();
	m=read();
	for(int i=1;i<=n;++i){
		v[i]=read();
//		v[i]%=mod;
	}
//	for(int i=1;i<=m;++i) a[i][0].push_back({0,0}),a[i][1].push_back({0,0});
	for(int i=1;i<=n;++i){
		b[i]=read();
		++c[b[i]][i&1];
		f[b[i]][i&1]+=v[i];
		f[b[i]][i&1]%=mod;
	}
	int ans=0;
	for(int i=1;i<=n;++i){
		ans+=i*((c[b[i]][i&1]-2)*v[i]%mod+f[b[i]][i&1])%mod;
		ans%=mod;
	}
	printf("%d\n",ans);
	return 0;
}

