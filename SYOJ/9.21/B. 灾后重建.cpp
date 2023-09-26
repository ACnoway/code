#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
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
const int N=40004,M=100005;
int n,m;
int p[N],dx[5]={1,-1,0,0},dy[5]={0,0,-1,1},q[N],h,t;
inline int find(int x){
	while(x!=p[x]) x=p[x]=p[p[x]];
	return p[x];
}

typedef pair<int,int> pii;
pii a[N];
struct edge{
	int u,v,w,d;
	bool operator <(const edge &x)const{
		if(u==x.u) return v<=x.v;
		return u<x.u;
	}
}b[N];

int idx=1,head[N],to[M],nxt[M];
pii w[M];
inline void add(int u,int v,int _w,int d){
	to[++idx]=v;
	w[idx]={_w,d};
	nxt[idx]=head[u];
	head[u]=idx;
}

bool vis[N];
void bfs(){
	h=t=0;
	q[++t]=1;
	vis[1]=1;
	int u,v,f,d;
	while(h<t){
		u=q[++h];
		for(int i=head[u];i;i=nxt[i]){
			v=to[i];
			if(!vis[v]){
				f=w[i].first,d=w[i].second;
				a[v]={a[u].first+dx[d]*f,a[u].second+dy[d]*f};
				q[++t]=v;
				vis[v]=1;
			}
		}
	}
}

struct wenti{
	int u,v,t,p;
	bool operator <(const wenti &x)const{
		return t<x.t;
	}
}qs[N];
int ans[N];

int main()
{
	n=read();
	m=read();
	for(int i=1;i<=n;++i) p[i]=i;
	for(int i=1;i<=m;++i){
		b[i].u=read(),b[i].v=read();
		b[i].w=read(),b[i].d=read()-1;
		add(b[i].u,b[i].v,b[i].w,b[i].d);
		add(b[i].v,b[i].u,b[i].w,b[i].d^1);
	}
	bfs();
	int K=read();
	for(int i=1;i<=K;++i){
		qs[i].u=read(),qs[i].v=read(),qs[i].t=read();
		qs[i].p=i;
	}
	sort(qs+1,qs+K+1);
	int now=1,u,v,uu,vv;
	for(int i=1;i<=K;++i){
		u=qs[i].u,v=qs[i].v;
		for(;now<=qs[i].t;++now){
			uu=find(b[now].u);
			vv=find(b[now].v);
			if(uu!=vv) p[vv]=uu;
		}
		uu=find(u);
		vv=find(v);
		ans[qs[i].p]=(uu==vv?(abs(a[u].first-a[v].first)+abs(a[u].second-a[v].second)):-1);
	}
	for(int i=1;i<=K;++i) printf("%d\n",ans[i]);
	return 0;
}
