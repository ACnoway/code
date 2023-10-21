#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#define int long long
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
const int N=100005;
int n,m,h,t,ans;
int idx=1,head[N],to[N<<1],nxt[N<<1],w[N<<1];
int a[N],q[N],val[N];
bool vis[N];
inline void add(int u,int v,int _w){
	to[++idx]=v;
	w[idx]=_w;
	nxt[idx]=head[u];
	head[u]=idx;
}
void dfs(int x,int die){
	int v;
//	fa[x]=die;
	if(!head[x]) return;
	for(int i=head[x];i;i=nxt[i]){
		v=to[i];
		if(v!=die){
			a[v]=w[i];
			dfs(v,x);
		}
	}
}
signed main()
{
	n=read();
	int u,v,_w;
	for(int i=1;i<n;++i){
		u=read(),v=read(),_w=read();
		add(u,v,_w);
		add(v,u,_w);
	}
	dfs(1,0);
	while(m--){
		int op=read(),x=read();
		if(op==1){
			int k=read();
			a[x]+=k;
		}
		else{
			ans=0;
			h=t=0;
			vis[x]=1;
			q[++t]=x;
			for(int i=1;i<=n;++i) vis[i]=0,val[i]=0;
			while(h<t){
				u=q[++h];
				for(int i=head[u];i;i=nxt[i]){
					v=to[i];
					if(vis[v]) continue;
					val[v]=val[u]+a[v];
					ans=max(ans,val[v]);
					q[++t]=v;
					vis[v]=1;
				}
			}
			printf("%lld\n",ans);
		}
	}
	return 0;
}
