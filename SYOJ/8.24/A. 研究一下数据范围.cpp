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
const int N=102;
int n,m,t;
int a[N][N],f[20004];
bool cmp(int x,int y){
	return x>y;
}
int main()
{
	m=read();
	n=read();
	t=read();
	for(int i=1;i<=m;++i){
		for(int j=1;j<=n;++j){
			a[j][i]=read();
		}
	}
	for(int i=1;i<=n;++i) sort(a[i]+1,a[i]+1+m);
	for(int i=1;i<=n;++i){
		for(int j=t;j>=0;--j){
			for(int k=1;k<=m;++k){
				if(j>(a[i][k]<<1)){
					f[j]=max(f[j],f[j-(a[i][k]<<1)-1]+k*i);
				}
			}
		}
	}
	int ans=0;
	for(int i=0;i<=t;++i) ans=max(ans,f[i]);
	printf("%d\n",ans);
	return 0;
}
