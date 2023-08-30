#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<climits>
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
const int N=2e5+86;

int n,m,r,ans=1145141919,h,t;
int a[N],f[N],q[N];
int main()
{
	n=read(); m=read();
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=n;i++)
	{
		while(h<t&&q[h+1]<i-m) ++h;
		while(h<t&&f[q[t]]>f[i-1]) --t;
		q[++t]=i-1;
		f[i]=f[q[h+1]]+a[i];
		if(i+m>n)
			ans=min(f[i],ans);
	}
	printf("%d\n",ans);
	return 0;
}

