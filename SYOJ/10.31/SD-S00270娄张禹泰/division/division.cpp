#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
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
const int N=200005;
int n,now,ans,h,t;
int idx=1,head[N],to[N<<1],nxt[N<<1],chu[N],w[N<<1];
int q[N],dis[N],Ans[N],p[N];
bool vis[N];
struct node{
	vector<int> s;
	int fa,dep,ms,md;
}a[N];
inline void add(int u,int v){
	to[++idx]=v;
	w[idx]=1;
	nxt[idx]=head[u];
	head[u]=idx;
	++chu[u];
}
void dfs_lian(int x,int die){
	p[x]=die;
	q[now++]=x;
	for(int i=head[x];i;i=nxt[i]){
		if(to[i]!=die) dfs_lian(to[i],x);
	}
}
void dfs1(int x,int die){
	a[x].fa=die;
	a[x].md=a[x].dep=a[die].dep+1;
	int v;
	for(int i=head[x];i;i=nxt[i]){
		v=to[i];
		if(v!=die){
			a[x].s.push_back(v);
			dfs1(v,x);
			if(a[v].md>a[x].md) a[x].ms=v,a[x].md=a[v].md;
		}
	}
}
void dfs(int x){
	int v;
	for(int i=head[x];i;i=nxt[i]){
		v=to[i];
		if(v==a[x].fa) continue;
		if(v==a[x].ms) w[i]=w[i^1]=0;
		dfs(v);
	}
}
inline void bfs(int x){
	h=t=0;
	q[++t]=x;
	dis[x]=0;
	int u,v;
	while(h<t){
		u=q[++h];
		vis[u]=1;
		for(int i=head[u];i;i=nxt[i]){
			v=to[i];
			if(!vis[v]){
				q[++t]=v;
				dis[v]=dis[u]+w[i];
			}
		}
	}
}
int main()
{
	freopen("division.in","r",stdin);
	freopen("division.out","w",stdout);
	n=read();
	for(int i=1;i<n;++i){
		int u=read(),v=read();
		add(u,v);
		add(v,u);
	}
	int sp=0,cnt=0;
	for(int i=1;i<=n;++i){
		if(chu[i]==1){
			sp=i;
			++cnt;
		}
	}
	if(cnt==2){
//		不给链也要链
		dfs_lian(sp,sp);
		for(int i=1;i<now-1;++i){
			Ans[q[i]]=min((n-i)*i,(n-(now-1-i))*(now-1-i));
		}
		for(int i=1;i<=n;++i) printf("%d\n",Ans[i]);
	}
	else{
		for(int i=1;i<=n;++i){
			for(int j=0;j<=n;++j){
				a[j].s.clear();
				a[j].md=a[j].fa=a[j].dep=a[j].ms=0;
			}
			for(int i=0;i<=idx;++i) w[i]=1;
			dfs1(i,i);
			dfs(i);
			ans=0;
			for(int j=1;j<=n;++j){
				bfs(j);
				for(int k=1;k<=n;++k){
					ans+=dis[k],dis[k]=0,vis[k]=0;
				}
			}
			printf("%d\n",ans/2);
		}
	}
	
	
	return 0;
}
