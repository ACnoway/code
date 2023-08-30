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
const int N=600,mod=1e9+7;
int n,m;
char a[N],b[N];
long long f[5][N][N];
inline void add(long long x,long long &y){
	y+=x;
	if(y>=mod) y-=mod;
}
int main()
{
	n=read();
	m=read();
	scanf("%s",a+1);
	scanf("%s",b+1);
	long long t;
	int cur=0;
	f[0][0][0]=1;
	for(int i=0;i<=n;++i,cur^=1){
		for(int j=0;j<=m;++j){
			for(int k=0;k<=n;++k){
				t=f[cur][j][k];
				if(i+j-k>m||i+j-k<0) continue;
				if(a[i+1]==a[k+1]) add(t,f[cur^1][j][k+1]);
				if(b[j+1]==b[i+j-k+1]) add(t,f[cur][j+1][k]);
				if(a[i+1]==b[i+j-k+1]) add(t,f[cur^1][j][k]);
				if(b[j+1]==a[k+1]) add(t,f[cur][j+1][k+1]);
				f[cur][j][k]=0;
			}
		}
	}
	printf("%lld\n",f[cur][m][n]);
	return 0;
}

