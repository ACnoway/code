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
const int N=30004;
const long long inf=1ll<<62;
int n,c,ma,mi=1000000000;
long long ans=1ll<<62;
long long f[N][602];
long long a[N];
void dfs(int x,int lst,long long res){
	if(x>n){
		ans=min(ans,res);
		return;
	}
	//no turn
	dfs(x+1,lst,res+(a[x]-lst)*(a[x]-lst));
	//turn
	dfs(x+1,a[x],res+c);
}
int main()
{
	n=read();
	c=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
		ma=max(ma,(int)a[i]),mi=min(mi,(int)a[i]);
	}
	for(int i=0;i<N;++i) for(int j=0;j<602;++j) f[i][j]=inf;
	int k=floor(sqrt(c+c));
	for(int i=-k;i<=k;++i) f[1][i+300]=i*i;
	long long t,m=(long long)c;
	for(int i=2;i<=n;++i){
		t=inf;
		for(int j=-k;j<=k;++j) t=min(t,f[i-1][j+300]);
		for(long long j=(long long)-k;j<=(long long)k;++j){
			if((j+a[i]-a[i-1])*(j+a[i]-a[i-1])<m+m)
				f[i][j+300]=f[i-1][j+a[i]-a[i-1]+300];
			f[i][j+300]=j*j+min(f[i][j+300],min(t+m,m+m));
		}
	}
	for(int i=-k;i<=k;++i) ans=min(ans,f[n][i+300]);
	printf("%lld\n",ans);
	return 0;
}
