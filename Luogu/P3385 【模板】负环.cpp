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
const int N=2003,M=6003,inf=1<<25;
int T,n,m;
int idx,head[N],to[M],nxt[M],w[M];
inline void addedge(int u,int v,int _w){
	to[++idx]=v;
	nxt[idx]=head[u];
	w[idx]=_w;
	head[u]=idx;
}
int q[N*N],dis[N],cnt[N],h,t;
bool vis[N];
bool spfa(){
	for(int i=0;i<N;++i) dis[i]=inf,vis[i]=0,cnt[i]=0;
	h=t=0;
	int u,v;
	q[++t]=1;
	dis[1]=0;
	vis[1]=1;
	while(h<t){
		u=q[++h];
		vis[u]=0;
		for(int i=head[u];i;i=nxt[i]){
			v=to[i];
			if(dis[v]>dis[u]+w[i]){
				dis[v]=dis[u]+w[i];
				cnt[v]=cnt[u]+1;
				if(cnt[v]>=n) return 1;
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
		idx=0;
		for(int i=0;i<N;++i) head[i]=0;
		for(int i=0;i<M;++i) to[i]=nxt[i]=w[i]=0;
		n=read();
		m=read();
		for(int i=1;i<=m;++i){
			int u=read(),v=read(),_w=read();
			addedge(u,v,_w);
			if(_w>=0) addedge(v,u,_w);
		}
		if(spfa()) printf("YES\n");
		else printf("NO\n");
	}
	
	return 0;
}
