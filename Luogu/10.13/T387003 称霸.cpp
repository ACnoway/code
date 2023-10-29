#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
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
const int N=1000006;
int n,m,ans=N;
int a[N],v[N],b[N];
bool vis[N];
bool chk(int x){
	for(int i=0;i<N;++i) vis[i]=0;
	for(int i=x;i;--i){
		if(vis[a[i]]) b[i]=0;
		else vis[a[i]]=1,b[i]=a[i];
	}
	int sum=0,cnt=0;
	for(int i=1;i<=x;++i){
		if(b[i]) sum-=v[a[i]],++cnt;
		else ++sum;
		if(sum<0) return 0;
	}
	return cnt==m;
}
int main()
{
	n=read();
	m=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
	}
	for(int i=1;i<=m;++i) v[i]=read();
	int l=1,r=n,mid,ans=-1;
	while(l<=r){
		mid=(l+r)>>1;
		if(chk(mid)) r=mid-1,ans=mid;
		else l=mid+1;
	}
	printf("%d\n",ans);
	return 0;
}
