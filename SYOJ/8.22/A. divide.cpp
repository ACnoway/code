#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<climits>
#define ll long long
using namespace std;
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
const int N=1000006;
ll n,c,h=1,t;
ll a[N],f[N],q[N];
//2S[i] * S[j] + (dp[i]-S[i]^2-C) = (dp[j]+S[j]^2)
//  k   *   x  +         b        =       y
inline ll X(ll j){
	return a[j];
}
inline ll Y(ll j){
	return f[j]+a[j]*a[j];
}
inline long double getk(ll x,ll y){
	return (long double)(Y(y)-Y(x))/(long double)(X(y)-X(x));
}
int main()
{
	while(scanf("%lld%lld",&n,&c)==2){
		for(int i=0;i<=n;++i) f[i]=-0x3f;
		a[0]=0;
		f[0]=0;
		h=1; t=0;
		for(int i=1;i<=n;++i){
			a[i]=read()+a[i-1];
		}
		q[++t]=0;
		int j;
		for(int i=1;i<=n;++i){
			while(h<t&&getk(q[h],q[h+1])<=2.0*a[i]) ++h;
			j=q[h];
			f[i]=f[j]+(a[i]-a[j])*(a[i]-a[j])+c;
			while(h<t&&getk(q[t],q[t-1])>=getk(q[t],i)) --t;
			q[++t]=i;
		}
		printf("%lld\n",f[n]);
	}
	
	return 0;
}
