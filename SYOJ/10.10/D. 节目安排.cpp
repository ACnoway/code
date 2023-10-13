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
const int N=100005,M=100005;
int T,n,m,h,t;
int idx,head[N],to[M],nxt[M],ru[N],q[N];
inline void add(int u,int v){
	to[++idx]=v;
	nxt[idx]=head[u];
	head[u]=idx;
	++ru[v];
}
int main()
{
	T=read();
	while(T--){
		n=read();
		m=read();
		idx=0;
		for(int i=0;i<=n;++i) head[i]=ru[i]=0;
		for(int i=1;i<=m;++i){
			int u=read(),v=read();
			add(u,v);
		}
		h=t=0;
		for(int i=1;i<=n;++i){
			if(!ru[i]) q[++t]=i;
		}
		while(h<t){
			
		}
	}
	return 0;
}
