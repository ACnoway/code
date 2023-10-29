#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#define int long long
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
const int N=1000006;
int n;
struct node{
	int u,v,w;
	bool operator <(const node &x)const{
		return w>x.w;
	}
}e[N],E[N];
int ru[N],f[N];
int idx=1,head[N],to[N],nxt[N],wi[N];
inline void add(int u,int v,int w){
	to[++idx]=v;
	nxt[idx]=head[u];
	wi[idx]=w;
	head[u]=idx;
}
int dis[N][3];
void dfs(int x,int die,int op){
	for(int i=head[x];i;i=nxt[i]){
		int v=to[i],d=wi[i];
		if(v==die) continue;
		dis[v][op]=dis[x][op]+d;
		dfs(v,x,op);
	}
}
signed main()
{
	n=read();
	for(int i=1;i<n;++i){
		int u=read(),v=read(),w=read();
		add(u,v,w);
		add(v,u,w);
	}
	dfs(1,0,0);
	int st=0,en=0;
	for(int i=1;i<=n;++i){
		st=(dis[i][0]>dis[st][0]?i:st);
	}
	dfs(st,st,1);
	for(int i=1;i<=n;++i){
		en=(dis[i][1]>dis)
	}
	return 0;
}
/*
  6
  1 2 1
  2 3 3
  3 4 5
  4 5 2
  5 6 4
 */
