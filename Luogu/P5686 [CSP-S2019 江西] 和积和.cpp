#include <iostream>
#include <cstdio>
#define ll unsigned long long
using namespace std;
inline ll read(){
	ll x=0,f=1;
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
inline void write(ll x){
	if(x<0){x=-x;putchar('-');}
	if(x>9) write(x/10);
	putchar(x%10);
}
const ll N=500005;
const ll P=1000000007;
ll n;
ll a[N],b[N],fa[N],fb[N];
signed main()
{
	cin>>n;
	for(int i=1;i<=n;++i) cin>>a[i];
	for(int i=1;i<=n;++i) cin>>b[i];
	for(int i=1;i<=n;++i){
		fa[i]=a[i]+fa[i-1];
		fb[i]=b[i]+fb[i-1];
	}
	ll ans=0;
	for(int i=1;i<=n;++i){
		for(int j=i;j<=n;++j){
			ans+=(((fa[j]-fa[i-1])%P)*((fb[j]-fb[i-1])%P))%P;
		}
	}
	cout<<ans%P<<endl;
	return 0;
}