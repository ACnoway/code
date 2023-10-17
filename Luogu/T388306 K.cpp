#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#define ll long long
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
const int mod=99999989;
int n,k;
char tmp;
string s;
int num[200],a[10000007];
ll f[10000007],q[10000007];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>n;
	cin>>tmp;
	cin>>s;
	for(int i=0;i<10;++i) num[i+'0']=i;
	for(int i=0;i<6;++i) num[i+'A']=10+i;
	
	k=num[(int)tmp];
	for(int i=0;i<n;++i) a[i]=num[(int)s[i]];
	f[n]=0; q[n]=1;
	for(int i=n-1;i>=0;--i) f[i]=(((ll)(a[i])*q[i+1])%mod+f[i+1])%mod,q[i]=(16*q[i+1])%mod;
	ll ans=0;
	for(int i=0;i<n;++i){
		ans+=((a[i]*(n-1-i))%mod*q[i+2])%mod,ans%=mod;
		if(a[i]>k){
			ans+=q[i+1];
			ans%=mod;
		}
		else if(a[i]==k){
			ans+=f[i+1]+1;
			ans%=mod;
		}
	}
	cout<<ans<<endl;
	return 0;
}
