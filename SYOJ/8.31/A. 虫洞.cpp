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
int n,m,cur;
int a[2][N][N],b[N][N];
void floyd(){
	for(int k=1;k<=n;++k)
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				a[cur^1][i][j]=min(a[cur^1][i][j],a[cur][i][k]+b[k][j]);
}
int main()
{
	n=read();
	m=read();
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			a[0][i][j]=a[1][i][j]=b[i][j]=inf;
		}
		a[0][i][i]=0;
	}
	for(int i=1;i<=m;++i){
		int u=read(),v=read(),w=read();
		b[u][v]=w;
	}
	for(int i=1;i<=n;++i,cur^=1){
		floyd();
		for(int j=1;j<=n;++j){
			if(a[cur^1][j][j]<0){
				cout<<i<<endl;
				return 0;
			}
		}
		for(int j=1;j<=n;++j){
			for(int k=1;k<=n;++k) a[cur][j][k]=inf;
		}
	}
	printf("0\n");
	return 0;
}
