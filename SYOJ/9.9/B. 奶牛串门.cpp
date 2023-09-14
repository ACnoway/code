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
const int N=50004,M=100005,inf=1<<27;
int n,m;
int need[7];
int idx=1,head[N],to[M<<1],nxt[M<<1],w[M<<1];
inline void addedge(int u,int v,int _w){
	to[++idx]=v;
	w[idx]=_w;
	nxt[idx]=head[u];
	head[u]=idx;
}
typedef pair<int,int> pii;
priority_queue<pii,vector<pii>,greater<pii> > q;
int dis[7][N];
bool vis[N];
void dij(int s){
	while(!q.empty()) q.pop();
	for(int i=0;i<=n;++i) vis[i]=0,dis[s][i]=inf;
	pii p;
	int u,v;
	dis[s][need[s]]=0;
	q.emplace((pii){0,need[s]});
	while(!q.empty()){
		p=q.top();
		q.pop();
		u=p.second;
		if(vis[u]) continue;
		vis[u]=1;
		for(int i=head[u];i;i=nxt[i]){
			v=to[i];
			if(dis[s][v]>dis[s][u]+w[i]){
				dis[s][v]=dis[s][u]+w[i];
				if(!vis[v]) q.emplace((pii){dis[s][v],v});
			}
		}
	}
}
int ans=inf,tmp;
void dfs(int x,int lst){
	if(tmp>ans) return;
	if(x==5){
		ans=min(ans,tmp);
		return;
	}
	for(int i=1;i<=5;++i){
		if(!vis[i]){
			tmp+=dis[lst][need[i]];
			vis[i]=1;
			dfs(x+1,i);
			tmp-=dis[lst][need[i]];
			vis[i]=0;
		}
	}
}
int main()
{
	n=read();
	m=read();
	for(int i=1;i<=5;++i) need[i]=read();
	need[6]=1;
	for(int i=1;i<=m;++i){
		int u=read(),v=read(),_w=read();
		addedge(u,v,_w);
		addedge(v,u,_w);
	}
	for(int i=1;i<=6;++i){
		dij(i);
	}
	for(int i=1;i<=5;++i) vis[i]=0;
	dfs(0,6);
	printf("%d",ans);
	return 0;
}
