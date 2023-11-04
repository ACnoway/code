#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
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
const int N=10000006,M=100000;
int t;
int p[N],dx[5]={0,0,1,0,-1},dy[5]={0,1,0,-1,0};
bool vis[N];
inline int find(int x){
	while(x!=p[x]) x=p[x]=p[p[x]];
	return p[x];
}
int main()
{
	t=read();
	for(int i=0;i<N;++i) p[i]=i;
	while(t--){
		int op=read(),xa=read(),ya=read(),xb=read(),yb=read(),u,v,nx,ny;
		if(op){
			u=find((xa-1)*M+ya);
			v=find((xb-1)*M+yb);
			printf("%d\n",(u==v?1:0));
		}
		else{
			if(xa>xb) swap(xa,xb);
			if(ya>yb) swap(ya,yb);
			u=find((xa-1)*M+ya);
			for(int i=xa;i<=xb;++i){
				for(int j=ya;j<=yb;++j){
					vis[(i-1)*M+j]=1;
					for(int k=0;k<5;++k){
						nx=i+dx[k],ny=j+dy[k];
						if(nx<=0||ny<=0||nx>N||ny>M) continue;
						if(vis[(nx-1)*M+ny]){	
							v=find((nx-1)*M+ny);
							p[v]=u;
						}
					}
				}
			}
		}
	}
	return 0;
}
