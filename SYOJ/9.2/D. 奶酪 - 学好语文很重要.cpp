#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<climits>
using namespace std;
typedef long long ll;
ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<3ll)+(x<<1ll)+(c^48);
		c=getchar();
	}
	return x*f;
}
const int N=102;
const ll inf=1ll<<60;
int T,n,h,t,cnt;
ll ans,m;
struct jz{
	ll mt[N][N];
	jz(){
		for(int i=0;i<N-1;++i) for(int j=0;j<N-1;++j) mt[i][j]=0;
	}
	jz operator *(const jz &x)const{
		jz c;
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j){
				c.mt[i][j]=-inf;
				for(int k=1;k<=n;++k)
					c.mt[i][j]=max(c.mt[i][j],mt[i][k]+x.mt[k][j]);
			}
		return c;
	}
}a,f[N];
bool check(jz x){
	for(int i=1;i<=n;++i) if(x.mt[1][i]>=m) return 1;
	return 0;
}
int main()
{
	T=(int)read();
	while(T--){
		n=(int)read();
		m=read();
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j){
				f[1].mt[i][j]=read();
				if(!f[1].mt[i][j]) f[1].mt[i][j]=-inf;
			}
		ans=1;
		for(cnt=1;cnt<N-1;++cnt){
			f[cnt+1]=f[cnt]*f[cnt];
			if(check(f[cnt+1])) break;
		}
		a=f[1];
		bool flag=0;
		for(int i=cnt;i;--i){
			jz b=a*f[i];
			if(!check(b)){
				a=b;
				ans+=(1ll<<(i-1));
			}
			else flag=1;
		}
		if(flag) printf("%lld\n",ans+1);
		else printf("-1\n");
	}
	return 0;
}
