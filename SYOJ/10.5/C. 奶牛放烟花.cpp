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
const int N=500005;
int n,m,s;
int idx=1,head[N],to[N<<1],nxt[N<<1],w[N<<1];
inline void add(int u,int v,int _w){
	to[++idx]=v;
	nxt[idx]=head[u];
	w[idx]=_w;
	head[u]=idx;
}
int ma[N],fa[N],ti[N];
int dfs(int x,int die,int tim){
	fa[x]=die;
	bool flg=0;
	for(int i=head[x];i;i=nxt[i]){
		if(to[i]!=die) flg=1,ma[x]=max(ma[x],dfs(to[i],x,tim+w[i]));
	}
	if(!flg) ma[x]=ti[x]=tim;
	return ma[x];
}
int ans;
void dfs1(int x,int now){
	for(int i=head[x];i;i=nxt[i]){
		if(to[i]!=fa[x]) dfs1(to[i],ma[s]-ma[x]);
	}
	ans+=ma[s]-ma[x]-now;
}
signed main()
{
	n=read();s=1;
	for(int i=1;i<n;++i){
		int u=read(),v=read(),_w=read();
		add(u,v,_w);
		add(v,u,_w);
	}
	dfs(s,0,0);
//	for(int i=1;i<=n;++i) cout<<ma[i]<<' ';
//	cout<<endl;
//	for(int i=1;i<=n;++i) cout<<ti[i]<<' ';
//	cout<<endl;
//	for(int i=1;i<=n;++i) cout<<fa[i]<<' ';
//	cout<<endl;
	dfs1(s,0);
	printf("%lld\n",ans);
	return 0;
}
