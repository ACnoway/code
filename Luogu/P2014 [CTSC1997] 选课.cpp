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
const int N=302,M=302;
int n,m;
int f[N][N];
int idx,head[N],nxt[M],to[M];
inline void add(int u,int v){
	to[++idx]=v;
	nxt[idx]=head[u];
	head[u]=idx;
}
void dp(int x){
	for(int v,i=head[x];i;i=nxt[i]){
		v=to[i];
		dp(v);
		for(int j=m+1;j>=1;--j){
			for(int k=0;k<j;++k){
				f[x][j]=max(f[x][j],f[v][k]+f[x][j-k]);
			}
		}
	}
}
int main()
{
	n=read();
	m=read();
	for(int i=1;i<=n;++i){
		int p=read();
		f[i][1]=read();
		add(p,i);
	}
	dp(0);
	printf("%d\n",f[0][m+1]);
	return 0;
}
