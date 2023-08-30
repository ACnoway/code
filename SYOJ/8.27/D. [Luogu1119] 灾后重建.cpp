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
const int N=202,inf=INT_MAX>>1;
int n,m;
int a[N][N];
int t[N];
int main()
{
	n=read();
	m=read();
	for(int i=0;i<n;++i) t[i]=read();
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			if(i!=j) a[i][j]=inf;
		}
	}
	int u,v,w;
	for(int i=1;i<=m;++i){
		u=read();
		v=read();
		w=read();
		a[u][v]=a[v][u]=w;
	}
	for(int k=0;k<n;++k)
		for(int i=0;i<n;++i)
			for(int j=0;j<n;++j)
				a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
	int T=read();
	while(T--){
		u=read();
		v=read();
		w=read();
		if(t[u]>w||t[v]>w||a[u][v]==inf) printf("-1\n");
		else printf("%d\n",a[u][v]);
	}
	return 0;
}
