#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<climits>
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
const int N=302,inf=INT_MAX>>1;
int T,n,m,k;
int a[N][N],b[N][N];
int main()
{
	T=read();
	while(T--){
		n=read();
		m=read();
		k=read();
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				a[i][j]=b[i][j]=inf;
			}
			a[i][i]=0;
		}
		for(int i=1;i<=m;++i){
			int u=read(),v=read(),w=read();
			a[u][v]=w;
			b[u][v]=1;
		}
		for(int i=1;i<=k;++i){
			int u=read(),v=read(),w=read();
			a[u][v]=-w;
			b[u][v]=1;
		}
		for(int k=1;k<=n;++k)
			for(int i=1;i<=n;++i)
				for(int j=1;j<=n;++j)
					a[i][j]=min(a[i][j],a[i][k]+a[k][j]),b[i][j]=min(b[i][j],b[i][k]+b[k][j]);
		int ans=inf;
		for(int i=1;i<=n;++i){
			if(a[i][i]<0) ans=min(ans,b[i][i]);
		}
		printf("%s\n",(ans==inf?"NO":"YES"));
	}
	return 0;
}
