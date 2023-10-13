#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#define ll long long
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
const int N=100005,M=1000006;
int n,m;
int dfid,cnt,dfn[N],low[N],siz[N];
ll ans[N];
bool ge[N];
int idx,head[N],nxt[M],to[M];
inline void add(int u,int v){
	to[++idx]=v;
	nxt[idx]=head[u];
	head[u]=idx;
}
void tarjan(int x,int die){
	dfn[x]=low[x]=++dfid;
	siz[x]=1;
	int ch=0,sum=0;
	for(int v,i=head[x];i;i=nxt[i]){
		v=to[i];
		if(!dfn[v]){
			tarjan(v,die);
			siz[x]+=siz[v];
			low[x]=min(low[x],low[v]);
			if(low[v]>=dfn[x]){
				ans[x]+=(ll)siz[v]*(n-siz[v]);
				sum+=siz[v];
				ch++;
				if(x!=die||ch>1){
					cnt+=(!ge[x]);
					ge[x]=1;
				}
			}
		}
		else low[x]=min(low[x],dfn[v]);
	}
	if(!ge[x]) ans[x]=2*(n-1);
	else ans[x]+=(ll)(n-sum-1)*(sum+1)+(n-1);
}
int main()
{
	n=read(); m=read();
	for(int i=1;i<=m;++i){
		int x=read(),y=read();
		add(x,y);
		add(y,x);
	}
	for(int i=1;i<=n;++i){
		if(!dfn[i]) tarjan(i,i);
	}
	for(int i=1;i<=n;++i) printf("%lld\n",ans[i]);
	return 0;
}
