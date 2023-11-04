#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#define int long long
using namespace std;
inline int read(){
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
int n,c,ans=1<<29;
int a[N];
void dfs(int x,int cnt){
	if(cnt>ans) return;
	if(x>n){
		int sum=0;
		for(int i=1;i<n;++i)
			sum+=abs(a[i]-a[i+1]);
		// cout<<endl;
		cnt+=sum*c;
		// for(int i=1;i<=n;++i) cout<<a[i]<<' ';
		// cout<<endl<<endl;
		ans=min(ans,cnt);
		return;
	}
	int tmp=a[x];
	for(int i=0;i<=max(a[x-1],a[x+1])-a[x];++i){
		a[x]=tmp+i;
		dfs(x+1,cnt+i*i);
		a[x]=tmp;
	}
}
signed main()
{
	n=read();
	c=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
	}
	dfs(1,0);
	printf("%lld\n",ans);
	return 0;
}
