#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<queue>
#include<climits>
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
const int N=200005,inf=INT_MAX>>1;
struct node{
	int x,y,p;
}a[N];
bool cmp1(node a,node b){
	return a.x<b.x;
}
bool cmp2(node a,node b){
	return a.y<b.y;
}
int n;
int idx=1,head[N],to[N<<2],nxt[N<<2],w[N<<2];
void addedge(int u,int v,int _w){
	to[++idx]=v;
	w[idx]=_w;
	nxt[idx]=head[u];
	head[u]=idx;
}
typedef pair<int,int> pii;
priority_queue<pii> q;
int dis[N];
bool vis[N];
void dij(){
	pii p;
	q.emplace((pii){0,0});
	int u,v,d;
	vis[0]=1;
	dis[0]=0;
	while(!q.empty()){
		p=q.top();
		q.pop();
		u=p.second,d=p.first;
		for(int i=head[u];i;i=nxt[i]){
			v=to[i];
			if(dis[v]>d+w[i]){
				dis[v]=d+w[i];
				if(!vis[v]) q.emplace((pii){dis[v],v}),vis[v]=1;
			}
		}
	}
}
int main()
{
	n=read();
	for(int i=0;i<=n;++i) dis[i]=inf;
	for(int i=0;i<n;++i){
		a[i].x=read();
		a[i].y=read();
		a[i].p=i;
	}
	sort(a,a+n,cmp1);
	for(int i=1;i<n;++i){
		addedge(a[i-1].p,a[i].p,a[i].x-a[i-1].x);
		addedge(a[i].p,a[i-1].p,a[i].x-a[i-1].x);
	}
	sort(a,a+n,cmp2);
	for(int i=1;i<n;++i){
		addedge(a[i-1].p,a[i].p,a[i].y-a[i-1].y);
		addedge(a[i].p,a[i-1].p,a[i].y-a[i-1].y);
	}
	dij();
	printf("%d\n",dis[n-1]);
	return 0;
}
