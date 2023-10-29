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
const int N=200005,M=400005,inf=1145141919;
int n,d,h,t;
int idx=1,head[N],to[M],nxt[M],ti[M],sl[M],ru[N];
inline void add(int u,int v,int w,int s){
	to[++idx]=v;
	ti[idx]=w;
	sl[idx]=s;
	nxt[idx]=head[u];
	head[u]=idx;
	++ru[v];
}
typedef pair<int,int> pii;
pii q[N];
bool vis[N];
int bfs(int x){
	bool flag=1;
	int res=0;
	h=t=0;
	for(int i=0;i<=n;++i) vis[i]=0;
	q[++t]=(pii){x,0};
	int u,w,v;
	vis[x]=1;
	while(h<t){
		u=q[++h].first;
		w=q[h].second;
		for(int i=head[u];i;i=nxt[i]){
			v=to[i];
			if(!vis[v]){
				res+=(!sl[i]);
				q[++t]=(pii){v,w+ti[i]};
				vis[v]=1;
				if(w+ti[i]>d){
					flag=0;
					break;
				}
			}
		}
		if(!flag) break;
	}
	if(!flag) return inf;
	else return res;
}
pii pre[N],nt[N],fp[N],fn[N];
void dfs(int x,int die){
//	cout<<"x="<<x<<endl;
	vis[x]=1;
	int v;
	for(int i=head[x];i;i=nxt[i]){
		v=to[i];
		if(v!=die&&!vis[v]){
			pre[v]={x,i};
			nt[x]={v,i^1};
			dfs(v,x);
		}
	}
}
int main()
{
	n=read();
	d=read();
	for(int i=1;i<n;++i){
		int u=read(),v=read(),w=read();
		add(u,v,w,0);
		add(v,u,w,1);
	}
	if(n<=5000){
		int ans=inf;
		for(int i=1;i<=n;++i){
			ans=min(ans,bfs(i));
		}
		if(ans==inf) printf("-1\n");
		else printf("%d\n",ans);
		return 0;
	}
	int tmp=0,tmpst=0,tmpen=0;
	for(int i=1;i<=n;++i){
		if(ru[i]==1){
			++tmp;
			if(!tmpst) tmpst=i;
			else tmpen=i;
		}
	}
	if(tmp==2){
		dfs(tmpst,0);
		int now=tmpst;
		fp[0]={0,0};
		fn[0]={0,0};
		pre[tmpst]={0,0};
		nt[tmpen]={0,0};
		do{
			fp[now]={fp[pre[now].first].first+ti[pre[now].second],fp[pre[now].first].second+sl[pre[now].second]};
			if(nt[now].first) now=nt[now].first;
			else break;
		}while(1);
		do{
			fn[now]={fn[nt[now].first].first+ti[nt[now].second],fn[nt[now].first].second+sl[nt[now].second]};
			if(pre[now].first) now=pre[now].first;
			else break;
		}while(1);
		int ans=inf;
		for(int i=tmpst;i;i=nt[i].first){
			if(max(fp[i].first,fn[i].first)<=d)
				ans=min(ans,fp[i].second+fn[i].second);
		}
		if(ans==inf) printf("-1\n");
		else printf("%d\n",ans);
	}
	return 0;
}
