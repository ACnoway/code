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
const int N=302;
int n,ans;
int a[N];
int main()
{
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	n=read();
	a[0]=-114514;
	for(int i=1;i<=n;++i){
		a[i]=read();
		if(a[i]!=a[i-1]+1) ++ans;
	}
	printf("%d\n",ans);
	return 0;
}
