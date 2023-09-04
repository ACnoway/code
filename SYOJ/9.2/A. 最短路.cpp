#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<climits>
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
const int N=100005,M=400005,mod=100003,inf=INT_MAX>>1;
int n,m;
int idx=1,head[N],to[M],nxt[M];
int cnt[N],dis[N];
bool vis[N];
typedef pair<int,int> pii;
bool operator <(pii a,pii b){
	return b.first<a.first;
}
void addedge(int u,int v){
	to[++idx]=v;
	nxt[idx]=head[u];
	head[u]=idx;
}
queue<pii> q;
void bfs(){
	pii p;
	q.emplace((pii){0,1});
	vis[1]=1;
	dis[1]=0;
	cnt[1]=1;
	int u,d,v;
	while(!q.empty()){
		p=q.front();
		q.pop();
		u=p.second,d=p.first+1;
		for(int i=head[u];i;i=nxt[i]){
			v=to[i];
			if(!vis[v]){
				vis[v]=1;
				q.emplace((pii){d,v});
				dis[v]=d;
			}
			if(dis[v]==d){
				cnt[v]+=cnt[u];
				cnt[v]%=mod;
			}
		}
	}
}
int main()
{
	n=read();
	m=read();
	for(int i=0;i<=n;++i) dis[i]=inf;
	int u,v;
	for(int i=0;i<m;++i){
		u=read(); v=read();
		if(u==v) continue;
		addedge(u,v);
		addedge(v,u);
	}
	bfs();
	for(int i=1;i<=n;++i){
		printf("%d\n",cnt[i]);
	}
	return 0;
}
