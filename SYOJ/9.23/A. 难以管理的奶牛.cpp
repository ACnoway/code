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
const int N=100005,M=400005;
int n,m;
int p[N];
bool huan[N];
inline int find(int x){
	while(p[x]!=x) x=p[x]=p[p[x]];
	return p[x];
}
int main()
{
	int u,v;
	while(scanf("%d%d",&n,&m)==2){
		for(int i=1;i<=n;++i) p[i]=i,huan[i]=0;
		for(int i=0;i<m;++i){
			scanf("%d%d",&u,&v);
			int uu=find(u),vv=find(v);
			if(uu==vv){
				huan[uu]=1;
			}
			else{
				p[vv]=uu;
				huan[uu]|=huan[vv];
			}
		}
		bool flag=1;
		for(int i=1;i<=n;++i){
			if(p[i]==i&&huan[i]==0){
				flag=0;
				break;
			}
		}
		if(flag) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
