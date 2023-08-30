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
const int N=50004;
int n,m,h,t;
int a[N],f[N],q[N];
bool check(int x){
	int ans=1145141919;
	for(int i=0;i<=n;++i) f[i]=q[i]=0;
	h=t=0;
	for(int i=1;i<=n;i++)
	{
		while(h<t&&q[h+1]<i-x) ++h;
		while(h<t&&f[q[t]]>f[i-1]) --t;
		q[++t]=i-1;
		f[i]=f[q[h+1]]+a[i];
		if(i+x>n)
			ans=min(f[i],ans);
	}
	if(ans<=m) return 1;
	else return 0;
}
int main()
{
	n=read();
	m=read();
	for(int i=1;i<=n;++i) a[i]=read();
	int l=0,r=n,mid;
	while(l<r){
		mid=(l+r)>>1;
		if(check(mid+1)) r=mid;
		else l=mid+1;
	}
	printf("%d\n",r);
	return 0;
}
