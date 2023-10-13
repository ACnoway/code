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
const int N=100005,M=200005;
int n,m;
int idx=1,head[N],to[M],nxt[M];
inline void add(int u,int v){
	to[++idx]=v;
	nxt[idx]=head[u];
	head[u]=idx;
}
int fa[N],p[N],ans[N],cnt[N];
struct node{
	int op,x,p;
}qs[N];
inline int find(int x){
	while(p[x]!=x) x=p[x]=p[p[x]];
	return p[x];
}
void dfs(int x,int die){
	fa[x]=die;
	p[x]=die;
	for(int i=head[x];i;i=nxt[i]) if(to[i]!=die) dfs(to[i],x);
}
int main()
{
	n=read();
	m=read();
	for(int i=1;i<n;++i){
		int u=read(),v=read();
		add(u,v);
		add(v,u);
	}
	dfs(1,0);
	p[1]=1;
	cnt[1]=1;
	for(int i=1;i<=m;++i){
		qs[i].op=read(),qs[i].x=read();
		qs[i].p=i;
		if(!qs[i].op) p[qs[i].x]=qs[i].x,++cnt[qs[i].x];
	}
	for(int i=m;i;--i){
		if(qs[i].op){
			ans[qs[i].p]=find(qs[i].x);
		}
		else{
			if(--cnt[qs[i].x]==0) p[qs[i].x]=fa[qs[i].x];
		}
	}
	for(int i=1;i<=m;++i) if(ans[i]) printf("%d\n",ans[i]);
	return 0;
}
