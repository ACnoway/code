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
const int N=1003,M=20004;
const long long inf=LONG_LONG_MAX>>2ll;
int n,m,k,ma;
int idx=1,head[N],to[M],nxt[M],w[M];
long long dis[N];
typedef pair<long long,int> pli;
bool vis[N];
void addedge(int u,int v,int _w){
	to[++idx]=v;
	w[idx]=_w;
	nxt[idx]=head[u];
	head[u]=idx;
}
priority_queue<pli> q;
bool operator <(pli a,pli b){
	return b.first<a.first;
}
bool dij(long long x){
	for(int i=0;i<=n;++i) dis[i]=inf,vis[i]=0;
	dis[1]=0ll;
	int u=0,v;
	for(int i=1;i<=n;++i){
		long long mi=inf;
		for(int j=1;j<=n;++j){
			if(!vis[j]&&dis[j]<mi){
				mi=dis[j];
				u=j;
			}
		}
		vis[u]=1;
		for(int j=head[u];j;j=nxt[j]){
			v=to[j];
			if(w[j]>x) dis[v]=min(dis[v],dis[u]+1ll);
			else dis[v]=min(dis[v],dis[u]);
		}
	}
	if(dis[n]==inf){
		printf("-1\n");
		exit(0);
	}
	if(dis[n]>k) return 0;
	return 1;
}
void erfen(){
	int l=0,r=ma,mid,ans=1145141919;
	while(l<=r){
		mid=(l+r)>>1;
		if(dij(mid)) r=mid-1,ans=min(ans,mid);
		else l=mid+1;
	}
	printf("%d\n",ans);
}
int main()
{
	n=read();
	m=read();
	k=read();
	int u,v,_w;
	for(int i=0;i<m;++i){
		u=read(); v=read();
		_w=read(); ma=max(ma,_w);
		addedge(u,v,_w);
		addedge(v,u,_w);
	}
	erfen();
	
	return 0;
}
