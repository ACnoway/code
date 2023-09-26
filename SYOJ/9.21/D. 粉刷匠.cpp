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
const int N=2000006;
int n,k,a,b;
int col[N],p[N];
int find(int x){
	while(x!=p[x]) x=p[x]=p[p[x]];
	return p[x];
}
int main()
{
	n=read();
	k=read();
	a=read();
	b=read();
	for(int i=0;i<=n+1;++i) p[i]=i;
	for(int i=k;i;--i){
		int l=(i*a+b)%n+1,r=(i*b+a)%n+1;
		if(l>r) swap(l,r);
		for(int j=find(l);j<=r;j=find(j)){
			col[j]=i; p[j]=j+1;
		}
	}
	for(int i=1;i<=n;++i) printf("%d\n",col[i]);
	return 0;
}
