#include<bits/stdc++.h>
#define ld long double
#define ll long long
#define ull unsigned long long
#define inf 1e18
using namespace std;
const int N=300005,M=600005;
int tot,e[M],fa[N],ne[M],h[N],top[N],siz[N],hson[N],dep[N],tim,dfn[N],w[N];
int n,a[N];
int read(){
	int x=0, f=1;
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
int qpow(int a,int b,int mm){
	int sum=1;
	while(b){
		if(b&1) sum=sum*a%mm;
		a=a*a%mm;
		b>>=1;
	}
	return sum;
}
void add(int u,int v){
	e[++tot]=v;
	ne[tot]=h[u];
	h[u]=tot;
}
void dfs1(int u,int ff,int d){
	dep[u]=d+1;
	siz[u]=1;
	fa[u]=ff;
	int maxn=0;
	for(int i=h[u];i;i=ne[i]){
		int v=e[i];
		if(v==ff) continue;
		dfs1(v,u,d+1);
		siz[u]+=siz[v];
		if(siz[v]>maxn) maxn=siz[v],hson[u]=v;
	}
}
void dfs2(int u,int ff){
	dfn[u]=++tim;
	if(hson[u]){
		top[hson[u]]=top[u];
		dfs2(hson[u],u);
	}
	for(int i=h[u];i;i=ne[i]){
		int v=e[i];
		if(v==ff) continue;
		if(!top[v]){
			top[v]=v;
			dfs2(v,v);
		}
	}
}
int get_lca(int x,int y){
	while(top[x]!=top[y]){
		if(dep[top[x]]>dep[top[y]]) x=fa[top[x]];
		else y=fa[top[y]];
	}
	return dep[x]>dep[y]?y:x;
}
void dfs(int u,int ff){
	for(int i=h[u];i;i=ne[i]){
		int v=e[i];
		if(v==ff) continue;
		dfs(v,u);
		w[u]+=w[v];
	}
}
int main(){
	top[1]=1;
	n=read();
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<n;i++){
		int u=read(),v=read();
		add(u,v),add(v,u);
	}
	dfs1(1,0,0);
	dfs2(1,0);
	for(int i=1;i<n;i++){
		int lca=get_lca(a[i],a[i+1]);
		w[a[i]]++,w[fa[a[i+1]]]++,w[lca]--,w[fa[lca]]--;
	}
	dfs(1,1);
	for(int i=1;i<=n;i++){
		printf("%d\n",i==a[n]?w[i]+1:w[i]);
	}
	return 0;
}
