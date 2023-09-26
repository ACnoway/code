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
const int N=202,M=4003,inf=1<<27;
int T,n,m;
int idx,head[N],nxt[M],to[M],w[M];
int dis[N],cnt[N],q[N*N],h,t;
bool vis[N];
inline void addedge(int u,int v,int _w){
	to[++idx]=v;
	w[idx]=_w;
	nxt[idx]=head[u];
	head[u]=idx;
}
inline void init(){
	idx=0;
	for(int i=0;i<N;++i) head[i]=-1;
	
}
bool spfa(){
	h=t=0;
	for(int i=0;i<=n;++i) dis[i]=inf,cnt[i]=0,vis[i]=0;
	q[++t]=n+1;
	dis[n+1]=0;
	vis[n+1]=1;
	int u,v;
	while(h<t){
		u=q[++h];
		vis[u]=0;
		for(int i=head[u];i!=-1;i=nxt[i]){
			v=to[i];
			if(dis[v]>dis[u]+w[i]){
				dis[v]=dis[u]+w[i];
				cnt[v]=cnt[u]+1;
				if(cnt[v]>n+1) return 1;
				if(!vis[v]) q[++t]=v,vis[v]=1;
			}
		}
	}
	return 0;
}
int main()
{
	T=read();
	while(T--){
		init();
		n=read();
		m=read();
		for(int i=0;i<=n;++i) addedge(n+1,i,0);
		for(int i=0;i<m;++i){
			int u=read(),v=read(),_w=read();
			addedge(u-1,v,_w);
			addedge(v,u-1,-_w);
		}
		if(spfa()) printf("false\n");
		else printf("true\n");
	}
	return 0;
}
