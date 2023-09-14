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
const int N=5003,M=12497510;
int n,m;
int idx=1,head[N],to[M<<1],nxt[M<<1];
double w[M<<1];
void addedge(int u,int v,double _w){
	to[++idx]=v;
	w[idx]=_w;
	nxt[idx]=head[u];
	head[u]=idx;
}
typedef pair<double,int> pdi;
priority_queue<pdi> q;
double dis[N];
bool vis[N];
void dij(){
	pdi p;
	int u,v;
	q.emplace((pdi){1.0,1});
	dis[1]=1.0;
	while(!q.empty()){
		p=q.top();
		q.pop();
		u=p.second;
		if(vis[u]) continue;
		vis[u]=1;
		for(int i=head[u];i;i=nxt[i]){
			v=to[i];
			if(dis[v]<dis[u]*w[i]){
				dis[v]=dis[u]*w[i];
				if(!vis[v]) q.emplace((pdi){dis[v],v});
			}
		}
	}
}
int main()
{
	n=read();
	m=read();
	for(int i=0;i<m;++i){
		int u=read(),v=read();
		double _w=(double)read();
		_w/=100.0; _w=1.0-_w;
		addedge(u,v,_w);
		addedge(v,u,_w);
	}
//	for(int i=0;i<=n;++i) dis[i]=1.0;
	dij();
	printf("%.3lf\n",dis[n]);
	return 0;
}
