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
int n,m;
bool t1[N][N],t2[N][N];
int main()
{
	n=read();
	m=read();
	int u,v;
	for(int i=1;i<=n;++i) t1[i][i]=t2[i][i]=1;
	for(int i=1;i<=m;++i){
		u=read();
		v=read();
		t1[u][v]=t2[v][u]=1;
	}
	for(int k=1;k<=n;++k){
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				t1[i][j]|=(t1[i][k]&&t1[k][j]);
				t2[i][j]|=(t2[i][k]&&t2[k][j]);
			}
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j) t1[i][j]|=t2[i][j];
	}
	int ans=0;
	for(int i=1;i<=n;++i){
		bool flag=1;
		for(int j=1;j<=n;++j){
			if(!t1[i][j]){
				flag=0;
				break;
			}
		}
		if(flag) ++ans;
	}
	printf("%d\n",ans);
	return 0;
}
