#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<climits>
#define int long long
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
const int N=100005,M=600005;
int n,m,tot,sum,cnt;
bool vis[M];
struct node{
	int u,v,dis,id;
	bool operator <(const node b)const{
		return dis<b.dis;
	}
};
vector<node> edge;
struct Node{
	int to,w;
};
vector<Node> e[N];
//-----并查集-----
int p[N];
int find(int x){
	while(p[x]!=x) x=p[x]=p[p[x]];
	return p[x];
}
inline void merge(int x,int y){
	p[find(x)]=find(y);
}
int dep[N];
int fa[25][N],Max[25][N],mMax[25][N];
void dfs(int x,int die){
	dep[x]=dep[die]+1;
	fa[0][x]=die;
	for(auto now:e[x]){
		int v=now.to,d=now.w;
		if(v==die) continue;
		Max[0][v]=d;
		dfs(v,x);
	}
}
int lca(int x,int y){
	if(dep[x]<dep[y]) swap(x,y);
	for(int i=20;i>=0;--i){
		if(dep[fa[i][x]]>=dep[y]) x=fa[i][x];
	}
	if(x==y) return x;
	for(int i=20;i>=0;--i){
		if(fa[i][x]!=fa[i][y]){
			x=fa[i][x];
			y=fa[i][y];
		}
	}
	return fa[0][x];
}
int fmax(int x,int tt,int w){
	int ans=0;
	for(int i=20;i>=0;--i){
		if(dep[fa[i][x]]>=dep[tt]){
			if(Max[i][x]==w) ans=max(ans,mMax[i][x]);
			else ans=max(ans,Max[i][x]);
			x=fa[i][x];
		}
	}
	return ans;
}
signed main()
{
	n=read();
	m=read();
	for(int i=1;i<=m;++i){
		int x=read(),y=read(),d=read();
		if(x==y) continue;
		edge.push_back({x,y,d,++cnt});
	}
	sort(edge.begin(),edge.end());
	for(int i=1;i<=n;++i) p[i]=i;
	for(auto now:edge){
		int x=now.u,y=now.v,d=now.dis,i=now.id;
		if(find(x)!=find(y)){
			sum+=d;
			tot++;
			vis[i]=1;
			merge(x,y);
			e[x].push_back({y,d});
			e[y].push_back({x,d});
		}
		if(tot==n-1) break;
	}
	dfs(1,0);
	for(int i=1;i<=20;++i){
		for(int j=1;j<=n;++j){
			fa[i][j]=fa[i-1][fa[i-1][j]];
			Max[i][j]=max(Max[i-1][j],Max[i-1][fa[i-1][j]]);
			mMax[i][j]=max(mMax[i-1][j],mMax[i-1][fa[i-1][j]]);
			if(Max[i-1][j]!=Max[i-1][fa[i-1][j]]){
				mMax[i][j]=max(mMax[i][j],min(Max[i-1][j],Max[i-1][fa[i-1][j]]));
			}
		}
	}
	int ans=LONG_LONG_MAX;
	for(auto now:edge){
		int u=now.u,v=now.v,d=now.dis,i=now.id;
		if(vis[i]) continue;
		int tt=lca(u,v);
		int xma=fmax(u,tt,d),yma=fmax(v,tt,d);
		if(max(xma,yma)!=d) ans=min(ans,sum+d-max(xma,yma));
	}
	printf("%lld\n",ans);
	return 0;
}
