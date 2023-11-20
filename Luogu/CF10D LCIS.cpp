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
const int N=502;
int n,m,tp;
int a[N],b[N],st[N];
int f[N][N],pre[N][N];
int main()
{
	n=read();
	for(int i=1;i<=n;++i) a[i]=read();
	m=read();
	for(int i=1;i<=m;++i) b[i]=read();
	a[0]=b[0]=-1;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			if(a[i]==b[j]){
				for(int k=0;k<j;++k){
					if(a[i]>b[k]&&f[i][j]<f[i-1][k]+1){
						f[i][j]=f[i-1][k]+1;
						pre[i][j]=k;
					}
				}
			}
			else{
				f[i][j]=f[i-1][j];
				pre[i][j]=pre[i-1][j];
			}
		}
	}
	int ans=0,sp=0;
	for(int i=1;i<=m;++i){
		if(ans<f[n][i]){
			ans=f[n][i];
			sp=i;
		}
	}
	printf("%d\n",ans);
	for(;sp;sp=pre[n][sp]){
		st[++tp]=b[sp];
	}
	while(tp) printf("%d ",st[tp--]);
	return 0;
}
