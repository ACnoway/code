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
const int N=1003;
int T,n,m,cnt;
int a[N][N],f[N][N];
typedef pair<int,int> pii;
pii p[N][N];
int main()
{
	T=read();
	while(T--){
		n=read();
		m=read();
		cnt=0;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				a[i][j]=read();
				if(a[i][j]) ++cnt;
				f[i][j]=0;
				p[i][j]={0,0};
			}
		}
		pii now;
		int x,y,ans=0;
		while(cnt){
			for(int i=1;i<=n;++i){
				for(int j=1;j<=m;++j){
					if(f[i-1][j]>f[i][j-1]){
						f[i][j]=f[i-1][j];
						p[i][j]={i-1,j};
					}
					else{
						f[i][j]=f[i][j-1];
						p[i][j]={i,j-1};
					}
					if(a[i][j]) ++f[i][j];
				}
			}
			now=p[n][m];
			x=now.first,y=now.second;
			while(x&&y){
				if(a[x][y]){
					--a[x][y];
					if(!a[x][y]) --cnt;
				}
				now=p[x][y];
				x=now.first,y=now.second;
			}
			++ans;
		}
		printf("%d\n",ans);
	}
	
	return 0;
}
