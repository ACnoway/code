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
const int N=302,M=502;
int n,m,dfid,col;
int a[N],c[N],fa[N];
int f[N][M];
int idx,head[N],nxt[N<<1],to[N<<1];
int idx1,head1[N],nxt1[N<<1],to1[N<<1];
int dfn[N],low[N],color[N],siz[N],val[N],ru[N];
int top,st[N];
bool vis[N];
inline void add(int u,int v){
	to[++idx]=v;
	nxt[idx]=head[u];
	head[u]=idx;
}
inline void add1(int u,int v){
	to1[++idx1]=v;
	nxt1[idx1]=head1[u];
	head1[u]=idx1;
}
void tarjan(int x){
	dfn[x]=low[x]=++dfid;
	st[++top]=x;
	vis[x]=1;
	int v;
	for(int i=head[x];i;i=nxt[i]){
		v=to[i];
		if(!dfn[v]){
			tarjan(v);
			low[x]=min(low[x],low[v]);
		}
		else if(vis[v]==1) low[x]=min(low[x],dfn[v]);
	}
	if(dfn[x]==low[x]){
		color[x]=++col;
		vis[x]=0;
		siz[col]=c[x];
		val[col]=a[x];
		while(st[top]!=x){
			color[st[top]]=col;
			siz[col]+=c[st[top]];
			val[col]+=a[st[top]];
			vis[st[top]]=0;
			--top;
		}
		--top;
	}
}
void dp(int x){
	for(int i=siz[x];i<=m;++i) f[x][i]=val[x];
	for(int v,i=head1[x];i;i=nxt1[i]){
		v=to1[i];
		dp(v);
		int tmp=m-siz[x];
		for(int j=tmp;j>=0;--j){
			for(int k=0;k<=j;++k){
				f[x][j+siz[x]]=max(f[x][j+siz[x]],f[v][k]+f[x][j+siz[x]-k]);
			}
		}
	}
}
void dfs(int x){
	vis[x]=1;
	for(int i=head[x];i;i=nxt[i]){
		if(!vis[to[i]]) dfs(to[i]);
	}
}
int main()
{
	n=read();
	m=read();
	for(int i=1;i<=n;++i) c[i]=read();
	for(int i=1;i<=n;++i) a[i]=read();
	for(int i=1;i<=n;++i){
		fa[i]=read();
		if(fa[i]) add(fa[i],i);
	}
	for(int i=1;i<=n;++i){
		if(!dfn[i]) tarjan(i);
	}
	for(int i=1;i<=n;++i){
		for(int v,j=head[i];j;j=nxt[j]){
			v=to[j];
			if(color[i]!=color[v]){
				add1(color[i],color[v]);
				++ru[v];
			}
		}
	}
	for(int i=1;i<=col;++i){
		if(!ru[i]) add1(0,i);
	}
	dp(0);
	printf("%d\n",f[0][m]);
	return 0;
}
