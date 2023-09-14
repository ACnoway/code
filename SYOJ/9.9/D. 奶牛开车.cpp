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
const int N=202,inf=1<<27,M=20004;
int n,m,s,t,c;
int idx,head[N],to[M],nxt[M],lth[M],sp[M];
inline void addedge(int u,int v,int l,int _v){
	to[++idx]=v;
	nxt[idx]=head[u];
	head[u]=idx;
	lth[idx]=l;
	sp[idx]=_v;
}
typedef pair<int,int> pii;
typedef pair<double,pii> pdii;
priority_queue<pair<double,pii> > q;
int dis[N][502];
pii pth[N][502];
bool vis[N][502];
void dij(int x){
	dis[x][c]=0;
	q.emplace((pdii){0.0,(pii){x,c}});
	pii p;
	int u,ps,pps,v;
	double ti;
	while(!q.empty()){
		p=q.top().second;
		q.pop();
		u=p.first; ps=p.second;
		if(vis[u][ps]) continue;
		vis[u][ps]=1;
		for(int i=head[u];i;i=nxt[i]){
			v=to[i];
			pps=(sp[i]?sp[i]:ps);
			ti=(double)lth[i]/(double)pps;
			if(dis[v][pps]>dis[u][ps]+ti){
				dis[v][pps]=dis[u][ps]+ti;
				pth[v][pps]=p;
				q.emplace((pdii){-dis[v][pps],(pii){v,pps}});
			}
		}
	}
}
void out(int x,int y){
	if(x==1){
		printf("%d ",s);
		return;
	}
	out(pth[x][y].first,pth[x][y].second);
	printf("%d ",x);
}
int main()
{
	n=read(); m=read();
	s=read(); t=read();
	c=read();
	for(int i=1;i<=m;++i){
		int u=read(),v=read(),l=read(),_v=read();
		addedge(u,v,l,_v);
	}
	for(int i=1;i<=n;++i){
		for(int j=0;j<502;++j){
			dis[i][j]=inf;
		}
	}
	dij(s);
	int mp;
	for(int i=0;i<502;++i){
		if(dis[t][i]<dis[t][mp]) mp=i;
	}
	out(t,mp);
	return 0;
}
