#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
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
const int N=100005;
int n,m;
int a[N],f[N],bit[N];
vector<int> b;
inline int lb(int x){return x&-x;}
void add(int x){
	for(;x<N;++bit[x],x+=lb(x));
}
int sum(int x){
	int res=0;
	for(;x;res+=bit[x],x-=lb(x));
	return res;
}
signed main()
{
	n=read();
	for(int i=1;i<=n;++i) a[i]=read();
	m=read();
	while(m--){
		for(int i=0;i<N;++i) bit[i]=0;
		int k=read();
		f[0]=0;
		for(int i=1;i<=n;++i) f[i]=a[i]-k+f[i-1];
		b.clear();
		for(int i=0;i<=n;++i) b.push_back(f[i]);
		sort(b.begin(),b.end());
		b.resize(unique(b.begin(),b.end())-b.begin());
		for(int i=0;i<=n;++i) f[i]=lower_bound(b.begin(),b.end(),f[i])-b.begin()+1;
		int ans=0;
		for(int i=n;i>=0;--i){
			ans+=sum(f[i]);
			add(f[i]);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
