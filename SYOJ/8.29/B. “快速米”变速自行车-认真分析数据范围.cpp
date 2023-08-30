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
const int N=102,inf=INT_MAX>>1;
int n,m;
int a[N][N];
bool b[N][N];
int ton[N];
inline int lb(int x){
	return x&(-x);
}
inline int dis(int x){
	int cnt=0;
	while(x){
		x-=lb(x);
		++cnt;
	}
	return cnt;
}
int main()
{
	n=read();
	m=read();
	for(int i=0;i<=n;++i) for(int j=0;j<=n;++j) a[i][j]=inf;
	for(int i=1;i<=m;++i){
		int u=read(),v=read();
		if(u==v) ton[++ton[0]]=u;
		a[u][v]=1;
		b[u][v]=1;
	}
	for(int k=1;k<=n;++k){
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				a[i][j]=(dis(a[i][j])<dis(a[i][k]+a[k][j])?a[i][j]:a[i][k]+a[k][j]);
				b[i][j]=b[i][j]||(b[i][k]&&b[k][j]);
			}
		}
	}
	for(int i=1;i<=ton[0];++i){
		if(b[1][ton[i]]&&b[ton[i]][n]){
			cout<<1<<endl;
			return 0;
		}
	}
//	int cnt=0;
//	while(n){
//		n-=lb(n);
//		++cnt;
//	}
//	cout<<cnt<<endl;
	cout<<dis(a[1][n])<<endl;
	return 0;
}
