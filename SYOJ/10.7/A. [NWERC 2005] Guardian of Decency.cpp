#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
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
const int N=1002,M=50004;
int T,n,m;
int gao[N];
char sex[N];
char yy[N][N],ty[N][N];
int match[N];
bool st[N],mp[N][N];
bool find(int x){
	for(int v=1;v<=m;++v){
		if(!st[v]&&mp[x][v]){
			st[v]=1;
			if(match[v]==0||find(match[v])){
				match[v]=x;
				return 1;
			}
		}
	}
	return 0;
}
bool chk(int x,int y){
	if(abs(gao[x]-gao[y])>40) return 1;
	if(sex[x]==sex[y]) return 1;
	if(strcmp(yy[x],yy[y])!=0) return 1;
	if(strcmp(ty[x],ty[y])==0) return 1;
	return 0;
}
int main()
{
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		m=n;
		for(int i=0;i<N;++i){
			for(int j=0;j<N;++j) mp[i][j]=0;
		}
		for(int i=1;i<=n;++i){
			scanf("%d %c%s%s",&gao[i],&sex[i],yy[i],ty[i]);
			for(int j=1;j<i;++j){
				if(!chk(i,j)){
					mp[i][j]=mp[j][i]=1;
				}
			}
		}
		int ans=0;
		for(int i=0;i<N;++i) match[i]=0;
		for(int i=1;i<=n;++i){
			for(int j=0;j<N;++j) st[j]=0;
			if(find(i)) ans++;
		}
		printf("%d\n",n-ans/2);
	}
	return 0;
}
