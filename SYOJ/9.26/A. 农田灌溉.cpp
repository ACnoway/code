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
const int N=305,M=100010;
int n,idx,ans;
struct edge{
	int u,v,d;
	bool operator <(const edge &x){
		return d<x.d;
	}
}e[M];
bool c[N][N];
int p[N];
int find(int x){
	while(p[x]!=x) x=p[x]=p[p[x]];
	return p[x];
}
inline void kruskal(){
	int u,v,d;
	for(int i=1;i<=idx;++i){
		u=find(e[i].u),v=find(e[i].v),d=e[i].d;
		if(u!=v){
			p[v]=u;
			ans+=d;
		}
	}
}
int main()
{
	n=read();
	for(int i=1;i<=n;++i){
		int d=read();
		e[++idx]=(edge){n+1,i,d};
		e[++idx]=(edge){i,n+1,d};
		p[i]=i;
	}
	p[n+1]=n+1;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			int d=read();
			if(i!=j){
				e[++idx]=(edge){i,j,d};
			}
		}
	}
	sort(e+1,e+idx+1);
	kruskal();
	printf("%d\n",ans);
	return 0;
}
