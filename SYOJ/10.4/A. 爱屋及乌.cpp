#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#ifdef ONLINE_JUDGE
#define debug(x)
#else
#define debug(x) cout<<' '<<#x<<'='<<x<<endl
#endif
using namespace std;
inline int read(){
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
const int N=20004,M=50004;
int n,m,dfid,col;
int dfn[N],low[N],color[N],vis[N],chu[N],sum[N];
int top,st[N];
int idx,head[N],nxt[M],to[M];
int idx1,head1[N],nxt1[M],to1[M];
bool lt[N][N];
inline void add(int u,int v){
	to[++idx]=v;
	nxt[idx]=head[u];
	head[u]=idx;
	lt[u][v]=1;
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
		sum[col]=1;
		while(st[top]!=x){
			color[st[top]]=col;
			++sum[col];
			vis[st[top]]=0;
			--top;
		}
		--top;
	}
}
int main()
{
	n=read();
	m=read();
	for(int i=1;i<=m;++i){
		int u=read(),v=read();
		if(!lt[u][v]) add(u,v);
	}
	for(int i=1;i<=n;++i){
		if(!dfn[i]) tarjan(i);
	}
	for(int i=1;i<=n;++i){
		for(int v,j=head[i];j;j=nxt[j]){
			v=to[j];
			if(color[i]!=color[v]){
				add1(color[i],color[v]);
				++chu[color[i]];
			}
		}
	}
	int cnt=0,ans=0;
	for(int i=1;i<=col;++i){
		if(chu[i]==0){
			++cnt;
			ans=sum[i];
		}
	}
	printf("%d\n",(cnt>1?0:ans));
	return 0;
}
