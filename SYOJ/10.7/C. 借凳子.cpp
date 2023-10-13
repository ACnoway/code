#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<queue>
#include<cstring>
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
const int N=205,M=10004,inf=1<<28;
int n,m,s,t,ans,maxflow;
int dep[N],ped[N];
bool a[N],b[N];
struct node{
	int to,nxt,w;
}e[M];
int idx=1,head[N],cur[N];
void addedge(int u,int v,int w){
	e[++idx].to=v;
	e[idx].w=w;
	e[idx].nxt=head[u];
	head[u]=idx;
	
	e[++idx].to=u;
	e[idx].w=0;
	e[idx].nxt=head[v];
	head[v]=idx;
}
void bfs(){
	memset(dep,-1,sizeof(dep));
	memset(ped,0,sizeof(ped));
	//bfs要逆序
	dep[t]=0;
	ped[0]=1;
	queue<int> q;
	int p;
	q.push(t);
	//正常宽搜
	while(!q.empty()){
		p=q.front();
		q.pop();
		for(int i=head[p];i;i=e[i].nxt){
			int v=e[i].to;
			if(dep[v]!=-1) continue;//不要重复访问
			q.push(v);
			dep[v]=dep[p]+1;
			++ped[dep[v]];
		}
	}
	return;
}
int dfs(int x,int flow){
	if(x==t){
		maxflow+=flow;
		return flow;
	}
	int used=0;
	for(int &i=cur[x];i;i=e[i].nxt){
		int v=e[i].to;
		if(e[i].w&&dep[v]+1==dep[x]){
			//如果还有剩余的流量以及没有断层
			int c=dfs(v,min(flow-used,e[i].w));
			if(c){
				e[i].w-=c;
				e[i^1].w+=c;
				used+=c;
			}
			if(used==flow) return used;
		}
	}
	//走到这里就说明还有剩余的流量没被用完
	//这样的话就要去更改这个点的深度，把它往后推一个
	//这样就能把这个点和其他的点分开，因为它跑不满给它的流量
	if(--ped[dep[x]]==0) dep[s]=N-1;
	++dep[x];
	++ped[dep[x]];
	return used;
}
int ISAP(){
	maxflow=0;
	bfs();
	while(dep[s]<n+n){
		memcpy(cur,head,sizeof(head));
		dfs(s,inf);
	}
	return maxflow;
}
signed main()
{
	int T=read();
	s=N-2,t=N-1;
	while(T--){
		n=read();
		memset(head,0,sizeof head);
		memset(a,0,sizeof a);
		memset(b,0,sizeof b);
		idx=1;
		for(int i=1;i<=n;++i){
			a[i]=read();
			if(a[i]==1) addedge(i+n,t,1);
		}
		int need=0;
		for(int i=1;i<=n;++i){
			b[i]=read();
			if((a[i]==1&&b[i]==0)||(a[i]==0)){
				addedge(s,i,1);
				++need;
			}
		}
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){	
				int x=read();
				if(x==1||i==j) addedge(i,j+n,1);
			}
		}
		if(ISAP()>=need) printf("1\n");
		else printf("0\n");
	}
	
	return 0;
}
