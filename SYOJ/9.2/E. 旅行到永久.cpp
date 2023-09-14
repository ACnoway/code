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
const int N=102,inf=1<<30;
int n,m,s;
double p;
double a[N];
double f[33][N][N];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i) scanf("%lf",&a[i]);
	scanf("%d%lf",&s,&p);
	int u,v;
	for(int k=0;k<32;++k)
		for(int i=0;i<=n;++i)
			for(int j=0;j<=n;++j)
				if(i!=j) f[k][i][j]=-inf;
	for(int i=1;i<=m;++i){
		scanf("%d%d",&u,&v);
		f[0][u][v]=p*a[v];
	}
	for(int t=1;t<32;++t){
		for(int k=1;k<=n;++k)
			for(int i=1;i<=n;++i)
				for(int j=1;j<=n;++j)
					f[t][i][j]=max(f[t][i][j],f[t-1][i][k]+f[t-1][k][j]*p);
		p*=p;
		if(p<=(1e-9)) break;
	}
	double ans=0.0;
	for(int t=1;t<32;++t)
		for(int i=1;i<=n;++i)
			ans=max(ans,f[t][s][i]);
	printf("%.1lf",ans+a[s]);
	return 0;
}
