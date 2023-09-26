#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<queue>
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
const int N=102,M=2003,inf=1<<27;
int n,m;
int idx=1,head[N],to[M],nxt[M],w[M];
inline void add(int u,int v,int _w){
	to[++idx]=v;
	nxt[idx]=head[u];
	w[idx]=_w;
	head[u]=idx;
}
int dis[N];
bool vis[N];
typedef pair<int,int> pii;
priority_queue<pii,vector<pii>,greater<pii> > q;
inline void dij(int x){
	while(!q.empty()) q.pop();
	for(int i=0;i<=n;++i) dis[i]=inf,vis[i]=0;
	dis[x]=0;
	q.emplace((pii){0,x});
	int u,v;
	while(!q.empty()){
		u=q.top().second;
		q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(int i=head[u];i;i=nxt[i]){
			v=to[i];
			if(dis[v]>dis[u]+w[i]){
				dis[v]=dis[u]+w[i];
				if(!vis[v]) q.emplace((pii){dis[v],v});
			}
		}
	}
}
int main()
{
	n=read();
	m=read();
	for(int i=1;i<=m;++i){
		int u=read(),v=read(),_w=read();
		add(u,v,_w);
		add(v,u,_w);
	}
	int ans=1<<30;
	for(int i=1;i<=n;++i){
		dij(i);
		int tmp=0;
		for(int j=1;j<=n;++j){
			for(int k=1;k<=n;++k)
				if(j!=i&&j!=k&&k!=i) tmp=max(tmp,dis[j]+dis[k]);
		}
		ans=min(ans,tmp);
	}
	printf("%d\n",ans);
	return 0;
}
