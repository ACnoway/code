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
const int N=100005,M=200005;
int n,m;
int idx,head[N],to[M],nxt[M],ru[N];
int f[N];
inline void add(int u,int v){
	to[++idx]=v;
	nxt[idx]=head[u];
	head[u]=idx;
	++ru[v];
}
int dfs(int x){
	if(f[x]) return f[x];
	if(!head[x]) f[x]=1;
	for(int i=head[x];i;i=nxt[i]){
		f[x]+=dfs(to[i]);
	}
	return f[x];
}
int main()
{
	n=read();
	m=read();
	for(int i=1;i<=m;++i){
		int u=read(),v=read();
		add(u,v);
	}
	int ans=0;
	for(int i=1;i<=n;++i){
		if(!ru[i]&&head[i]) ans+=dfs(i);
	}
	printf("%d\n",ans);
	return 0;
}
