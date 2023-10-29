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
const int N=102,inf=1<<28;
int n,m,ans=inf;
int a[N][N],f[N][N];
bool vis[N][N];
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
void dfs(int x,int y,int cnt,int c){
	if(x==n&&y==n){
		ans=min(ans,cnt);
		return;
	}
	for(int i=0;i<4;++i){
		int nx=x+dx[i],ny=y+dy[i];
		if(nx<1||ny<1||nx>n||ny>n||vis[nx][ny]) continue;
		if(a[nx][ny]==2){
			if(a[x][y]!=2&&cnt+2<f[nx][ny]){
				vis[nx][ny]=1;
				f[nx][ny]=cnt+2;
				dfs(nx,ny,cnt+2,c);
				vis[nx][ny]=0;
			}
			else continue;
		}
		else{
			if(a[nx][ny]==c&&cnt<f[nx][ny]){
				vis[nx][ny]=1;
				f[nx][ny]=cnt;
				dfs(nx,ny,cnt,c);
				vis[nx][ny]=0;
			}
			else if(cnt+1<ans&&cnt+1<f[nx][ny]){
				vis[nx][ny]=1;
				f[nx][ny]=cnt+1;
				dfs(nx,ny,cnt+1,a[nx][ny]);
				vis[nx][ny]=0;
			}
		}
	}
}
int main()
{
	n=read();
	m=read();
	for(int i=0;i<=n;++i) for(int j=0;j<=n;++j) a[i][j]=2,f[i][j]=inf;
	for(int i=1;i<=m;++i){
		int x=read(),y=read(),c=read();
		a[x][y]=c;
	}
	dfs(1,1,0,a[1][1]);
	if(ans!=inf) printf("%d\n",ans);
	else printf("-1\n");
	return 0;
}
