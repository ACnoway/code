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
const int N=102,inf=1ll<<60;
int n,m,h,t;
int a[N],b[N],v[N],chu[N],ru[N],q[N*N];
int mp[N][N];
signed main()
{
	n=read(); m=read();
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j) mp[i][j]=-inf;
		mp[i][i]=1;
	}
	for(int i=1;i<=n;++i) a[i]=read(),b[i]=read(),v[i]=a[i];
	for(int i=1;i<=m;++i){
		int x=read(),y=read(),w=read();
		mp[x][y]=max(mp[x][y],w);
		++chu[x];
		++ru[y];
	}
	for(int i=1;i<=n;++i){
		if(!ru[i]&&a[i]>0) q[++t]=i;
	}
	int u;
	while(h<t){
		u=q[++h];
		for(int i=1;i<=n;++i){
			if(u!=i&&mp[u][i]!=-inf){
				if(v[u]>0) v[i]+=v[u]*mp[u][i];
				--ru[i];
				if(!ru[i]) q[++t]=i,v[i]-=b[i];
			}
		}
	}
	bool flag=0;
	for(int i=1;i<=n;++i){
		if(!chu[i]&&v[i]>0){
			printf("%lld %lld\n",i,v[i]);
			flag=1;
		}
	}
	if(!flag) printf("-1\n");
	return 0;
} 
