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
const int N=1003;
int n,m,h,t;
int cnt[N],c[N],can[N][N],a[N][N];
typedef pair<int,int> pii;
pii q[N*N];
bool vis[N][N];
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
void bfs(int st){
	for(int i=0;i<=n;++i) for(int j=0;j<=m;++j) vis[i][j]=0;
	h=t=0;
	q[++t]={1,st};
	vis[1][st]=1;
	if(1==n) can[st][++cnt[st]]=st;
	int x,y,nx,ny;
	while(h<t){
		x=q[++h].first,y=q[h].second;
		for(int i=0;i<4;++i){
			nx=x+dx[i],ny=y+dy[i];
			if(nx>0&&nx<=n&&ny>0&&ny<=m&&!vis[nx][ny]&&a[nx][ny]<a[x][y]){
				q[++t]={nx,ny};
				vis[nx][ny]=1;
				if(nx==n) can[st][++cnt[st]]=ny;
			}
		}
	}
}
bool cmp(pii a,pii b){
	return a.first>b.first;
}
signed main()
{
	n=read();
	m=read();
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			a[i][j]=read();
		}
	}
	int ans=0;
	for(int i=1;i<=m;++i){
		bfs(i);
		c[i]=cnt[i];
	}
	for(int i=0;i<=n;++i) for(int j=0;j<=m;++j) vis[i][j]=0;
	for(int ti=1;ti<=m;++ti){
		bool lft=0;
		for(int i=1;i<=m;++i)
			if(!vis[n][i]){
				lft=1;
				break;
			}
		if(lft){
			int ma=0,mp=1;
			for(int i=1;i<=m;++i){
				for(int j=1;j<=c[i];++j){
					if(vis[n][can[i][j]]) --cnt[i],can[i][j]=0;
				}
				if(cnt[i]>ma){
					ma=cnt[i],mp=i;
				}
			}
			for(int i=1;i<=c[mp];++i){
				if(can[mp][i]){
					vis[n][can[mp][i]]=1;
				}
			}
			cnt[mp]=c[mp]=0;
			++ans;
		}
	}
	int lft=0;
	for(int i=1;i<=m;++i)
		if(!vis[n][i])
			++lft;
	if(!lft) printf("1\n%d\n",ans);
	else printf("0\n%d\n",lft);
	return 0;
}
