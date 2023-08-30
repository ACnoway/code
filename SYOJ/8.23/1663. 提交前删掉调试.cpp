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
const int N=100005;
int n,c,m;
int a[N];
int f[2][102];
int main()
{
	n=read();
	c=read();
	int now=1;
	for(int i=1;i<=n;++i) a[i]=read(),m=max(m,a[i]);
	for(int i=0;i<=m;++i) f[0][i]=f[1][i]=1145141919;
	for(int i=a[1];i<=m;++i) f[now][i]=(i-a[1])*(i-a[1]);
	for(int i=2;i<=n;++i){
		now^=1;
		int k=1145141919;
		for(int j=a[i-1];j<=m;++j){
			k=min(k,f[now^1][j]-j*c);
			if(j>=a[i]) f[now][j]=k+(j-a[i])*(j-a[i])+c*j;
		}
		k=1145141919;
		for(int j=m;j>=a[i];--j){
			k=min(k,f[now^1][j]+j*c);
			f[now][j]=min(f[now][j],k-c*j+(j-a[i])*(j-a[i]));
		}
		for(int j=0;j<=m;++j) f[now^1][j]=1145141919;
	}
	int ans=1145141919;
	for(int i=a[n];i<=m;++i) ans=min(ans,f[now][i]);
	printf("%d\n",ans);
	return 0;
}
