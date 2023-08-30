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
const int N=100005;
int n,k,ans,l,r,ma;
int a[N],sum[N];
int idx=1,head[N<<1],to[N<<1],nxt[N<<1];
bool flag;
void addedge(int u,int v){
	to[++idx]=v;
	nxt[idx]=head[u];
	head[u]=idx;
}
int main()
{
	n=read();
	k=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
		l=max(l,a[i]);
		r+=a[i];
	}
	if(k==n) printf("%d\n",l);
	return 0;
}
