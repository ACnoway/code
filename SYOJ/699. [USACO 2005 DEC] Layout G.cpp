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
const int N=2003,M=40004,inf=-(1<<26);
int n,m1,m2;
int idx,head[N],to[M],nxt[M],w[M];
inline void addedge(int u,int v,int _w){
	to[++idx]=v;
	w[idx]=_w;
	nxt[idx]=head[u];
	head[u]=idx;
}
int dis[N],cnt[N],q[N*N],h,t;
bool vis[N];
bool spfa(){
	h=t=0;
	for(int i=0;i<=n;++i) dis[i]=inf,vis[i]=0,cnt[i]=0;
	dis[1]=0;
	q[++t]=1;
	vis[1]=1;
	int u,v;
	while(h<t){
		u=q[++h];
		vis[u]=0;
		for(int i=head[u];i;i=nxt[i]){
			v=to[i];
			if(dis[v]<dis[u]+w[i]){
				dis[v]=dis[u]+w[i];
				cnt[v]=cnt[u]+1;
				if(cnt[v]>=n) return 1;
				if(!vis[v]) q[++t]=v,vis[v]=1;
			}
		}
	}
	return 0;
}
signed main()
{
	n=read();
	m1=read();
	m2=read();
	for(int i=1;i<n;++i) addedge(i+1,i,0);
	for(int i=1;i<=m1;++i){
		int u=read(),v=read(),_w=read();
		addedge(u,v,-_w);
	}
	for(int i=1;i<=m2;++i){
		int u=read(),v=read(),_w=read();
		addedge(v,u,_w);
	}
	if(spfa()) printf("-1\n");
	else printf("%lld\n",(dis[n]==inf?-2:-dis[n]));
	return 0;
}
