#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<iomanip>
#include<queue>
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
const int N=1003,inf=1<<30;
int n,m,k;
typedef pair<int,int> pii;
string mp[N];
int a[N][N];
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
int idx=1,head[N],to[N*N],nxt[N*N],w[N*N];
priority_queue<pii,vector<pii>,greater<pii> > q;
bool vis[N];
inline void addedge(int u,int v,int _w){
	to[++idx]=v;
	w[idx]=_w;
	nxt[idx]=head[u];
	head[u]=idx;
}
inline double dis(double x1,double y1,double x2,double y2){
	return sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
}
void dij(int st){
	for(int i=0;i<=n*m;++i) vis[i]=0;
	while(!q.empty()) q.pop();
	pii p;
	q.emplace((pii){a[st][st],st});
	int u,v,d;
	while(!q.empty()){
		p=q.top();
		q.pop();
		u=p.second; d=a[st][u];
		if(vis[u]) continue;
		vis[u]=1;
		for(int i=head[u];i;i=nxt[i]){
			v=to[i];
			if(a[st][v]>d+w[i]){
				a[st][v]=d+w[i];
				if(!vis[v]) q.emplace((pii){a[st][v],v});
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>n>>m>>k;
	for(int i=0;i<n;++i){
		cin>>mp[i];
	}
	for(int i=0;i<=n*m;++i){
		for(int j=0;j<=n*m;++j) a[i][j]=inf;
	}
	int nx,ny,u,v;
	for(int i=0;i<n;++i)
		for(int j=0;j<m;++j){
			u=j+i*m;
			if(mp[i][j]=='1') a[u][u]=1;
			else a[u][u]=0;
			for(int k=0;k<4;++k){
				nx=i+dx[k],ny=j+dy[k];
				v=ny+nx*m;
				if(nx<0||nx>=n||ny<0||ny>=m) continue;
				if(mp[nx][ny]=='1'){
					addedge(u,v,1);
				}
				else{
					addedge(u,v,0);
				}
			}
		}
	for(int i=0;i<n*m;++i){
		dij(i);
	}
	double ans=0.00000;
	for(int i=0;i<n*m;++i)
		for(int j=0;j<n*m;++j){
			if(a[i][j]<=k){
				ans=max(ans,dis((double)(i%m),(double)(i/m),(double)(j%m),(double)(j/m)));
			}
		}
	cout<<fixed<<setprecision(6)<<ans<<endl;
	return 0;
}
