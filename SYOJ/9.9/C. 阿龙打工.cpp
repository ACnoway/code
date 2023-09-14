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
const int N=300,inf=1<<27;
int l,m,n,k,s;
int a[N][N];

int main()
{
	l=read();
	m=read();
	n=read();
	k=read();
	s=read();
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j) a[i][j]=-inf;
	}
	for(int i=1;i<=m;++i){
		int u=read(),v=read();
		a[u][v]=max(a[u][v],l);
	}
	for(int i=1;i<=k;++i){
		int u=read(),v=read(),w=read();
		a[u][v]=max(a[u][v],l-w);
	}
	for(int k=1;k<=n;++k)
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				a[i][j]=max(a[i][j],a[i][k]+a[k][j]);
	bool flag=0;
	int ans=l;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j) ans=max(ans,a[i][j]);
		if(a[i][i]>0) flag=1;
	}
	if(flag) printf("-1\n");
	else printf("%d\n",(ans==l?ans:ans+l));
	return 0;
}
