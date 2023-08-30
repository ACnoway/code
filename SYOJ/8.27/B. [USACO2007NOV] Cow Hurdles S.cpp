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
const int N=302;
int n,m,T;
int a[N][N];
int main()
{
	n=read();
	m=read();
	T=read();
	int u,v,w;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			if(i==j) a[i][j]=0;
			else a[i][j]=1145141919;
		}
	}
	for(int i=1;i<=m;++i){
		u=read();
		v=read();
		w=read();
		a[u][v]=w;
	}
	for(int k=1;k<=n;++k)
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				a[i][j]=min(max(a[i][k],a[k][j]),a[i][j]);
	while(T--){
		u=read();
		v=read();
		if(a[u][v]==1145141919) printf("-1\n");
		else printf("%d\n",a[u][v]);
	}
	return 0;
}
