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
int n,k;
int a[N];
int dikge(int l,int r,int k){
	if(l>=r) return a[l];
	int i=l-1,j=r+1,x=a[rand()%(r-l+1)+l];
	while(i<j){
		while(a[++i]<x);
		while(a[--j]>x);
		if(i<j) swap(a[i],a[j]);
	}
    if(j-l+1>=k) return dikge(l,j,k);
    else return dikge(j+1,r,k-(j-l+1));
}
int main()
{
	srand(time(0));
	n=read();
	k=read();
	for(int i=1;i<=n;++i) a[i]=read();
	printf("%d\n",dikge(1,n,k));
	return 0;
}
