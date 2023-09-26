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
const int N=10004,M=10004,inf=1<<27;
int n,m;
int idx,head[N],to[M],nxt[M],w[M];
inline void addedge(int u,int v,int _w){
	to[++idx]=v;
	w[idx]=_w;
	nxt[idx]=head[u];
	head[u]=idx;
}
int dis[N],q[N*N],cnt[N],h,t;
bool vis[N];
bool spfa(){
	h=t=0;
	for(int i=0;i<=n;++i) dis[i]=inf,vis[i]=0,cnt[i]=0;
	dis[n+1]=0;
	q[++t]=n+1;
	vis[n+1]=1;
	int u,v;
	while(h<t){
		u=q[++h];
		vis[u]=0;
		for(int i=head[u];i;i=nxt[i]){
			v=to[i];
			if(dis[v]>dis[u]+w[i]){
				dis[v]=dis[u]+w[i];
				cnt[v]=cnt[u]+1;
				if(cnt[v]>n) return 1;
				if(!vis[v]) q[++t]=v,vis[v]=1;
			}
		}
	}
	return 0;
}
int main()
{
	n=read();
	m=read();
	for(int i=1;i<=n;++i) addedge(n+1,i,0);
	for(int i=1;i<=m;++i){
		int u=read(),v=read(),_w=read();
		addedge(v,u,_w);
	}
	if(spfa()) printf("NO\n");
	else{
		for(int i=1;i<=n;++i) printf("%d ",dis[i]);
	}
	return 0;
}
