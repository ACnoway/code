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
const int N=100005,M=4000006;
int n,m,h,t,ans;
int idx=1,head[N],to[M],nxt[M];
int pre[N],nex[N],q[N],col[N];
bool vis[N],cov[N];
inline void rmv(int x){
	pre[nex[x]]=pre[x];
	nex[pre[x]]=nex[x];
}
inline void addedge(int u,int v){
	to[++idx]=v;
	nxt[idx]=head[u];
	head[u]=idx;
}
int main()
{
	n=read();
	m=read();
	for(int i=1;i<=m;++i){
		int u=read(),v=read();
		addedge(u,v);
		addedge(v,u);
	}
	for(int i=1;i<=n;++i){
		pre[i]=i-1;
		nex[i]=i+1;
	}
	nex[0]=1; nex[n]=0;
	while(nex[0]){
		h=t=0;
		q[++t]=nex[0];
		nex[0]=nex[nex[0]];
		pre[nex[q[t]]]=0;
		int p;
		while(h<t){
			p=q[++h];
			for(int i=head[p];i;i=nxt[i]) vis[to[i]]=1;
			int now=nex[0];
			while(now){
				if(!vis[now]){
					q[++t]=now;
					rmv(now);
				}
				now=nex[now];
			}
			for(int i=head[p];i;i=nxt[i]) vis[to[i]]=0;
		}
		col[++ans]=h;
	}
	sort(col+1,col+ans+1);
	printf("%d\n",ans);
	for(int i=1;i<=ans;++i) printf("%d ",col[i]);
	return 0;
}
