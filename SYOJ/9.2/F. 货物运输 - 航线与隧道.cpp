#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
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
const int N=25003,M=150005,inf=1<<29;
int n,m1,m2,s,h,t;
typedef pair<int,int> pii;
vector<pii> p[N],r[N];
vector<int> cnt[N];
int bl[N],q[N],dis[N],rd[N];
bool vis[N];
void bfs(int x,int col){
	h=t=0;
	q[++t]=x;
	bl[x]=col;
	cnt[col].push_back(x);
	int u;
	while(h<t){
		u=q[++h];
		for(pii v:r[u])
			if(!bl[v.first]) q[++t]=v.first,bl[v.first]=col,cnt[col].push_back(v.first);
	}
}
priority_queue<pii,vector<pii>,greater<pii> > pq;
void dij(int x){
	while(!pq.empty()) pq.pop();
	pii now;
	int u,v;
	for(int i:cnt[x])
		if(dis[i]<inf) pq.emplace((pii){dis[i],i});
	while(!pq.empty()){
		now=pq.top();
		pq.pop();
		u=now.second;
		if(vis[u]) continue;
		vis[u]=1;
		for(pii e:r[u]){
			v=e.first;
			if(dis[v]>dis[u]+e.second){
				dis[v]=dis[u]+e.second;
				if(!vis[v]) pq.emplace((pii){dis[v],v});
			}
		}
		for(pii e:p[u]){
			dis[e.first]=min(dis[e.first],dis[u]+e.second);
		}
	}
}
int main()
{
	n=read();
	m1=read();
	m2=read();
	s=read();
	for(int i=1;i<=m1;++i){
		int u=read(),v=read(),w=read();
		r[u].emplace_back((pii){v,w});
		r[v].emplace_back((pii){u,w});
	}
	for(int i=1;i<=m2;++i){
		int u=read(),v=read(),w=read();
		p[u].emplace_back((pii){v,w});
	}
	int col=0;
	for(int i=1;i<=n;++i)
		if(!bl[i]) bfs(i,++col);
	for(int i=1;i<=n;++i)
		for(pii v:p[i]) ++rd[bl[v.first]];
	for(int i=0;i<=n;++i) dis[i]=inf;
	h=t=0;
	dis[s]=0;
	for(int i=1;i<=col;++i)
		if(!rd[i]) q[++t]=i;
	int tmp;
	while(h<t){
		tmp=q[++h];
		dij(tmp);
		for(int i:cnt[tmp]){
			for(pii v:p[i])
				if(--rd[bl[v.first]]==0) q[++t]=bl[v.first];
		}
	}
	for(int i=1;i<=n;++i){
		if(dis[i]==inf) printf("NO PATH\n");
		else printf("%d\n",dis[i]);
	}
	return 0;
}
