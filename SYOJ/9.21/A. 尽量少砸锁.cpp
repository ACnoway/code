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
const int N=1000006,M=2000006;
int n;
int p[N];
inline int find(int x){
	while(x!=p[x]) x=p[x]=p[p[x]];
	return p[x];
}
int main()
{
	n=read();
	for(int i=1;i<=n;++i) p[i]=i;
	for(int i=1;i<=n;++i){
		int u=read();
		int uu=find(u),ii=find(i);
		p[ii]=uu;
	}
	int ans=0;
	for(int i=1;i<=n;++i) if(p[i]==i) ++ans;
	printf("%d\n",ans);
	return 0;
}
