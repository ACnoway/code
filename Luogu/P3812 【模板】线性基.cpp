#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#define int long long
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
const int N=102;
int n;
int a[N],p[N];
inline void cha(int x){
	for(int i=62;i>=0;--i){
		if(!(x>>i)) continue;
		if(!p[i]){
			p[i]=x;
			return;
		}
		x^=p[i];
	}
}
signed main()
{
	n=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
		cha(a[i]);
	}
	int ans=0;
	for(int i=62;i>=0;--i)
		ans=max(ans,ans^p[i]);
	printf("%lld\n",ans);
	return 0;
}
