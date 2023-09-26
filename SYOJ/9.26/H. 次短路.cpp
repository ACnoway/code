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
const int N=5003,M=200005,inf=1<<27;
int n,m;
int idx=1,head[N],to[M],nxt[M],w[M];
inline void add(int u,int v,int _w){
	to[++idx]=v;
	w[idx]=_w;
	nxt[idx]=head[u];
	head[u]=idx;
}
typedef pair<int,int> pii;
typedef pair<int,pii> piii;
priority_queue<piii,vector<piii>,greater<piii> > q;
int dis[2][N];
bool vis[2][N];
inline void dij(){
	for(int i=1;i<=n;++i) dis[0][i]=dis[1][i]=inf,vis[0][i]=vis[1][i]=0;
	dis[0][1]=0;
	q.emplace((piii){0,(pii){1,0}});
	int u,v,k;
	piii p;
	while(!q.empty()){
		p=q.top();
		q.pop();
		u=p.second.first,k=p.second.second;
		if(vis[k][u]) continue;
		vis[k][u]=1;
		for(int i=head[u];i;i=nxt[i]){
			v=to[i];
			if(dis[0][v]>dis[k][u]+w[i]){
				//如果可以更新最短路
				//次短路更新
				dis[1][v]=dis[0][v];
				q.emplace((piii){dis[1][v],(pii){v,1}});
				//最短路更新
				dis[0][v]=dis[k][u]+w[i];
				q.emplace((piii){dis[0][v],(pii){v,0}});
			}
			else if(dis[1][v]>dis[k][u]+w[i]){
				//可以更新次短路
				dis[1][v]=dis[k][u]+w[i];
				q.emplace((piii){dis[1][v],(pii){v,1}});
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
	dij();
	printf("%d\n",dis[1][n]);
	return 0;
}
