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
const int N=100005,M=200005,inf=1<<27;
int n,m;
int idx,head[N],to[M],nxt[M],w[M];
int idx1,head1[N],to1[M],nxt1[M],w1[M];
inline void addedge(int u,int v,int _w){
	to[++idx]=v;
	w[idx]=_w;
	nxt[idx]=head[u];
	head[u]=idx;
}
inline void add1(int u,int v,int _w){
	to1[++idx1]=v;
	w1[idx1]=_w;
	nxt1[idx1]=head1[u];
	head1[u]=idx1;
}
int dfn[N],low[N],color[N],ru[N],st[N],f[N],cnt[N];
int h,dfid,col;
bool vis[N];
void tarjan(int x){
	dfn[x]=low[x]=++dfid;
	st[++h]=x;
	vis[x]=1;
	int v;
	for(int i=head[x];i;i=nxt[i]){
		v=to[i];
		if(!dfn[v]){
			tarjan(v);
			low[x]=min(low[x],low[v]);
		}
		else if(vis[v]) low[x]=min(low[x],dfn[v]);
	}
	if(dfn[x]==low[x]){
		color[x]=++col;
		vis[x]=0;
		++cnt[col];
		while(st[h]!=x){
			color[st[h]]=col;
			vis[st[h]]=0;
			++cnt[col];
			--h;
		}
		--h;
	}
}
int q[N],t;
int main()
{
	n=read();
	m=read();
	for(int i=1;i<=m;++i){
		int c=read(),u=read(),v=read();
		switch (c) {
		case 1:
			addedge(u,v,0);
			addedge(v,u,0);
			break;
		case 2:
			addedge(u,v,1);
			break;
		case 3:
			addedge(v,u,0);
			break;
		case 4:
			addedge(v,u,1);
			break;
		case 5:
			addedge(u,v,0);
			break;
		}
	}
	for(int i=1;i<=n;++i) if(!dfn[i]) tarjan(i);
	for(int u=1,v;u<=n;++u){
		for(int j=head[u];j;j=nxt[j]){
			v=to[j];
			if(color[u]==color[v]&&w[j]==1){
				printf("-1\n");
				return 0;
			}
			else if(color[u]!=color[v]){
				add1(color[u],color[v],w[j]);
				++ru[color[v]];
			}
		}
	}
	h=t=0;
	for(int i=1;i<=col;++i){
		if(!ru[i]){
			q[++t]=i;
			f[i]=1;
		}
	}
	int u,v;
	while(h<t){
		u=q[++h];
		for(int i=head1[u];i;i=nxt1[i]){
			v=to1[i];
			ru[v]--;
			f[v]=max(f[v],f[u]+w1[i]);
			if(!ru[v]) q[++t]=v;
		}
	}
	long long ans=0;
	for(int i=1;i<=col;++i) ans+=(long long)f[i]*cnt[i];
	printf("%lld\n",ans);
	return 0;
}
