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
const int N=402,inf=1<<27;
int n,m,ma;
int a[N][N];
int s[10004],t[10004];
int main()
{
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	for(int i=0;i<N;++i){
		for(int j=0;j<N;++j) a[i][j]=inf;
		a[i][i]=0;
	}
	n=read();
	m=read();
	for(int i=1;i<=n;++i) s[i]=read(),ma=max(ma,s[i]);
	for(int i=1;i<=n;++i) t[i]=read(),ma=max(ma,t[i]);
	for(int i=1;i<=m;++i){
		int u=read(),v=read(),w=read();
		a[u][v]=min(a[u][v],w);
		ma=max(ma,max(u,v));
	}
	for(int k=1;k<=ma;++k)
		for(int i=1;i<=ma;++i)
			for(int j=1;j<=ma;++j)
				a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
	int ans=0,tmp=inf;
	for(int i=1;i<=n;++i){
		tmp=inf;
		for(int j=1;j<=ma;++j){
			tmp=min(tmp,a[s[i]][j]+a[t[i]][j]);
		}
		if(tmp==inf){
			printf("-1\n");
			return 0;
		}
		else ans+=tmp;
	}
	printf("%d\n",ans);
	return 0;
}
