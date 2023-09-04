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
long long f[N][N];
int main()
{
	n=read();
	m=read();
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j) a[i][j]=inf; 
	for(int i=1;i<=m;++i){
		int u=read(),v=read(),w=read();
		if(w<a[u][v]){
			a[u][v]=a[v][u]=w;
			f[u][v]=f[v][u]=1;
		}
		else if(w==a[u][v]){
			++f[u][v];
			++f[v][u];
		}
	}
	for(int k=1;k<=n;++k)
		for(int i=1;i<=n;++i)
			for(int j=i+1;j<=n;++j){
				if(a[i][j]==a[i][k]+a[k][j]){
					f[i][j]=f[j][i]=f[i][j]+f[i][k]*f[k][j];
				}
				else if(a[i][j]>a[i][k]+a[k][j]){
					a[i][j]=a[j][i]=a[i][k]+a[k][j];
					f[i][j]=f[j][i]=f[i][k]*f[k][j];
				}
			}
	double ans=0.0;
	for(int k=1;k<=n;++k){
		ans=0.0;
//		cout<<"-----------\nk="<<k<<endl;
		for(int i=1;i<=n;++i){
			if(i==k) continue;
			for(int j=i+1;j<=n;++j){
				if(a[i][j]!=a[i][k]+a[k][j]) continue;
				ans+=(double)f[i][k]*(double)f[k][j]/(double)f[i][j];
//				cout<<"i= "<<i<<" j= "<<j<<endl;
//				cout<<"fik="<<f[i][k]<<endl;
//				cout<<"fkj="<<f[k][j]<<endl;
//				cout<<"fij="<<f[i][j]<<endl;
			}
		}
		printf("%.3lf\n",ans);
	}
	return 0;
}
