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
const int N=5000006,M=10000007,inf=1<<30;
int n,m,s,e;
int idx=1,head[N],to[M],nxt[M],w[M];
typedef pair<int,int> pii;
priority_queue<pii,vector<pii>,greater<pii> > q;
int dis[N];
bool vis[N];
inline void addedge(int u,int v,int _w){
	to[++idx]=v;
	w[idx]=_w;
	nxt[idx]=head[u];
	head[u]=idx;
}
void dij(int st){
	pii p;
	q.emplace((pii){0,st});
	dis[st]=0;
	int u,v,d;
	while(!q.empty()){
		p=q.top();
		q.pop();
		u=p.second; d=dis[u];
		if(vis[u]) continue;
		vis[u]=1;
		for(int i=head[u];i;i=nxt[i]){
			v=to[i];
			if(dis[v]>d+w[i]){
				dis[v]=d+w[i];
				if(!vis[v]) q.emplace((pii){dis[v],v});
			}
		}
	}
}
int main()
{
	n=read();
	s=read(); e=read();
	for(int i=1;i<=n;++i){
		m=read();
		for(int j=1;j<=m;++j){
			int v=read();
			if(j>1) addedge(i,v,1);
			else addedge(i,v,0);
		}
	}
	for(int i=1;i<=n;++i) dis[i]=inf;
	dij(s);
	printf("%d\n",(dis[e]==inf?-1:dis[e]));
	return 0;
}
