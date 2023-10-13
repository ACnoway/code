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
const int N=200005,M=1000006;
int n,dfid,ans=N;
int dfn[N],low[N],vis[N];
int idx,head[N],nxt[M],to[M];
inline void add(int u,int v){
	to[++idx]=v;
	nxt[idx]=head[u];
	head[u]=idx;
}
bool ge[N];
void tarjan(int x,int die){
	dfn[x]=low[x]=++dfid;
	vis[x]=1;
	int v,ch=0;
	for(int i=head[x];i;i=nxt[i]){
		v=to[i];
		if(!dfn[v]){
			++ch;
			tarjan(v,x);
			low[x]=min(low[x],low[v]);
			if(low[v]>=dfn[x]&&x!=die) ge[x]=1;
		}
		else if(vis[v]==1) low[x]=min(low[x],dfn[v]);
	}
	if(ch>=2&&x==die) ge[x]=1;
}
int A,B;
void dfs(int x,bool &dh){
	if(x==B){
		dh=1;
		return;
	}
	vis[x]=1;
	int v;
	bool have=0;
	for(int i=head[x];i;i=nxt[i]){
		v=to[i];
		if(!vis[v]) dfs(v,have);
	}
	if(have&&ge[x]&&x!=A&&x!=B){
		ans=min(ans,x);
	}
	dh|=have;
}
int main()
{
	n=read();
	while(1){
		int u=read(),v=read();
		if(u==0) break;
		add(u,v);
		add(v,u);
	}
	for(int i=1;i<=n;++i){
		if(!dfn[i]) tarjan(i,i);
	}
	A=read(),B=read();
	for(int i=0;i<=n;++i) vis[i]=0;
	bool tmp=0;
	dfs(A,tmp);
	printf("%d\n",(ans==N?-1:ans));
	return 0;
}
