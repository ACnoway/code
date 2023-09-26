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
const int N=400005,M=400005;
int n,m;
int idx=1,head[N],to[M],nxt[M];
int dfn[N],low[N],cut[N],dfid,cnt;
bool ge[N],vis[N];
inline void addedge(int u,int v){
	to[++idx]=v;
	nxt[idx]=head[u];
	head[u]=idx;
}
void tarjan(int x,int die){
	int ch=0;
	dfn[x]=low[x]=++dfid;
	vis[x]=1;
	for(int i=head[x],v;i!=-1;i=nxt[i]){
		v=to[i];
		if(!dfn[v]){
			ch++;
			tarjan(v,x);
			low[x]=min(low[x],low[v]);
			if(low[v]>=dfn[x]&&x!=die){
				cnt+=(!ge[x]);
				++cut[x];
				ge[x]=1;
			}
		}
		else if(vis[v]) low[x]=min(low[x],dfn[v]);
	}
	if(ch>=2&&x==die){
		cut[x]=ch;
		cnt+=(!ge[x]);
		ge[x]=1;
	}
	if(ge[x]&&x!=die) ++cut[x];
}
int main()
{
	n=read();
	m=read();
	for(int i=0;i<=n;++i) head[i]=-1;
	for(int i=1;i<=m;++i){
		int u=read(),v=read();
		addedge(u,v);
		addedge(v,u);
	}
	int ans=0;
	for(int i=0;i<n;++i){
		if(!dfn[i]) ++ans,tarjan(i,i);
	}
	cout<<ans<<endl;
	int k=read();
	while(k--){
		int u=read();
		if(ge[u]) ans+=cut[u]-1;
		printf("%d\n",ans);
	}
	return 0;
}

