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
const int D=102,N=22;
int d,n,c,m,k;
int f[D],a[N][N];
bool can[N][D];
void floyd(int x){
	for(int k=1;k<=n;++k)
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j){
				if(can[i][x]||can[j][x]||can[k][x]) continue;
				a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
			}
}
int main()
{
	d=read();
	n=read();
	c=read();
	m=read();
	for(int i=1;i<=m;++i){
		int u=read(),v=read(),w=read();
		a[u][v]=a[v][u]=min(a[u][v],w);
	}
	for(int i=1;i<=d;++i){
		f[]
	}
	return 0;
}
