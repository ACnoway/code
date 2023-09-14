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
const int N=40004,M=200005,inf=1<<30;
int n,m;
typedef pair<int,int> pii;
typedef pair<int,pii> piii;
pii a[N];
pii s,t;
int idx=1,head[N],to[M],nxt[M];
pii dis[N];
bool vis[N];
void addedge(int u,int v){
	to[++idx]=v;
	nxt[idx]=head[u];
	head[u]=idx;
}
priority_queue<pii,vector<pii>,greater<pii> > q;
void dij(pii x){
	while(!q.empty()) q.pop();
	for(int i=0;i<=(n<<1);++i) vis[i]=0,dis[i]={inf,i};
	pii p;
	q.emplace((pii){0,x.first});
	dis[x.first]=(pii){0,x.second};
	int u,v;
	pii tmp;
	while(!q.empty()){
		p=q.top();
		q.pop();
		u=p.second;
		if(vis[u]) continue;
		vis[u]=1;
		for(int i=head[u];i;i=nxt[i]){
			v=to[i];
			if(dis[v].first>dis[u].first+(abs(dis[u].second-v)<<1)+1){
				dis[v]=(pii){dis[u].first+(abs(dis[u].second-v)<<1)+1,u};
				if(!vis[v]) q.emplace((pii){dis[v].first,v});
			}
		}
	}
	
}
int main()
{
	n=read();
	m=read();
	for(int i=1;i<=m;++i){
		int u=read(),v=read()+n;
		addedge(u,v);
		addedge(v,u);
	}
	s.first=read(),s.second=read()+n;
	t.first=read(),t.second=read()+n;
	dij(s);
	int ans=inf;
	ans=min(ans,dis[t.first].first+(abs(dis[t.first].second-t.second)<<1));
	ans=min(ans,dis[t.second].first+(abs(dis[t.second].second-t.first)<<1));
	dij((pii){s.second,s.first});
	ans=min(ans,dis[t.first].first+(abs(dis[t.first].second-t.second)<<1));
	ans=min(ans,dis[t.second].first+(abs(dis[t.second].second-t.first)<<1));
	if(ans==inf) printf("-1\n");
	else printf("%d\n",ans);
	return 0;
}
