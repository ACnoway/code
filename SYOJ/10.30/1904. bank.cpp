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
const int N=500005,M=100000;
int T,n,m;
int p[52*N];
bool vis[52*N];
int dx[]={1,0,-1,0},dy[]={0,1,0,-1};
struct node{
	int f[N];
	bool vis[N];
	void init(){
		for(int i=1;i<N;++i) f[i]=i;
	}
	inline int find(int x){
		while(x!=f[x]) x=f[x]=f[f[x]];
		return f[x];
	}
	inline int nxt(int x){
		if(vis[x]) return find(x)+1;
		else return x;
	}
	inline void update(int x){
		vis[x]=1;
		if(vis[x]&&vis[x-1]&&find(x)!=find(x-1)){
			f[find(x-1)]=x;
		}
		if(vis[x]&&vis[x+1]&&find(x)!=find(x+1)){
			f[find(x)]=x+1;
		}
	}
}a[52];
inline int ip(int x,int y){
	return (x-1)*M+y;
}
inline int find(int x){
	while(x!=p[x]) x=p[x]=p[p[x]];
	return p[x];
}
int main()
{
	for(int i=1;i<N;++i) p[i]=i;
	for(int i=1;i<=50;++i) a[i].init();
	T=read();
	while(T--){
		int op=read(),xa=read(),ya=read(),xb=read(),yb=read();
		if(op){
			int xx=ip(xa,ya),yy=ip(xb,yb);
			if(!vis[xx]||!vis[yy]) printf("0\n");
			else{
				if(find(xx)==find(yy)) printf("1\n");
				else printf("0\n");
			}
		}
		else{
			if(xa>xb) swap(xa,xb);
			if(ya>yb) swap(ya,yb);
			for(int i=xa;i<=xb;++i){
				int j=a[i].nxt(ya);
				while(j<=yb){
					int ipp=ip(i,j),ppi;
					vis[ipp]=1;
					for(int k=0;k<4;++k){
						int nx=i+dx[k],ny=j+dy[k];
						ppi=ip(nx,ny);
						if(vis[ipp]&&vis[ppi]){
							int uu=find(ipp),vv=find(ppi);
							if(uu!=vv) p[vv]=uu;
						}
					}
					a[i].update(j);
					j=a[i].nxt(j);
				}
			}
		}
	}
	return 0;
}
