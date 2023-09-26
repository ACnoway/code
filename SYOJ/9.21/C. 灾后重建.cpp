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
const int N=500005;
int n,m;
int p[N],dep[N],siz[N],a[N];
int find(int x){
	if(p[x]==x) return x;
	int y=find(p[x]);
	dep[x]=dep[p[x]]+1;
	return y;
}
inline int lca(int x,int y){
	int ans=0;
	while(x!=y){
		if(dep[x]<dep[y]) swap(x,y);
		ans=max(ans,a[x]);
		x=p[x];
	}
	return ans;
}
int main()
{
	n=read(); m=read();
	for(int i=1;i<=n;++i) p[i]=i,siz[i]=1;
	int ans=0,cnt=0;
	while(m--){
		int op=read(),x=read()^ans,y=read()^ans;
		int xx=find(x),yy=find(y);
		if(op){
			if(xx==yy) ans=lca(x,y);
			else ans=0;
			printf("%d\n",ans);
		}
		else{
			++cnt;
			if(xx!=yy){
				if(siz[xx]>=siz[yy]){
					p[yy]=xx; a[yy]=cnt;
					siz[xx]+=siz[yy];
				}
				else{
					p[xx]=yy; a[xx]=cnt;
					siz[yy]+=siz[xx];
				}
			}
		}
	}
	return 0;
}
