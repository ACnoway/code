#include<iostream>
#include<cmath>
#define int long long
using namespace std;
const int mod=100003;
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
int qpow(int a,int b){
	int res=1;
	while(b){
		if(b&1) res*=a,res%=mod;
		a*=a,a%=mod;
		b>>=1;
	}
	return res;
}
signed main()
{
	int n,m;
	m=read(); n=read();
	int all=qpow(m,n),ok=(qpow(m-1,n-1)*m%mod)%mod;
	cout<<(all+mod-ok)%mod<<endl;
	return 0;
}
