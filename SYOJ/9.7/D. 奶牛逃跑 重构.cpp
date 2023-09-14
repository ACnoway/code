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
const int N=40004,M=100005,inf=1<<30;
int n,m,s,t;
int idx=1,head[N],to[M<<1],nxt[M<<1],w[M<<1];
struct node{
	int x,y,p;
}a[N];
typedef pair<int,int> pii;
inline void addedge(int u,int v,int _w){
	to[++idx]=v;
	w[idx]=_w;
	nxt[idx]=head[u];
	head[u]=idx;
}
pii dis[N];
bool vis[N];
priority_queue<pii,vector<pii>,greater<pii> > q;
bool cmp1(node a,node b){
	if(a.x!=b.x) return a.x<b.x;
	return a.y<b.y;
}
bool cmp2(node a,node b){
	if(a.y!=b.y) return a.y<b.y;
	return a.x<b.x;
}
int main()
{
	n=read();
	m=read();
	s=m+1,t=m+2;
	for(int i=1;i<=m+2;++i){
		a[i].x=read(),a[i].y=read()+n;
		addedge(a[i].x,a[i].y,1);
		addedge(a[i].y,a[i].x,1);
		a[i].p=i;
	}
	sort(a+1,a+3+m,cmp1);
	for(int i=1;i<m+2;++i){
		if(a[i].x==a[i+1].x){
			addedge(a[i].p,a[i+1].p,(a[i+1].y-a[i].y)<<1);
			addedge(a[i+1].p,a[i].p,(a[i+1].y-a[i].y)<<1);
		}
	}
	sort(a+1,a+3+m,cmp2);
	for(int i=1;i<m+2;++i){
		if(a[i].y==a[i+1].y){
			addedge(a[i].p,a[i+1].p,(a[i+1].x-a[i].x)<<1);
			addedge(a[i+1].p,a[i].p,(a[i+1].x-a[i].x)<<1);
		}
	}
	dij(s);
	int ans=inf;
	return 0;
}
