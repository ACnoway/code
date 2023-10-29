#include<iostream>
#define int long long
using namespace std;
const int mod=998244353;
int qp(int a,int b){
	int res=1;
	while(b){
		if(b&1ll) res=res*a%mod;
		a=a*a%mod;
		b>>=1ll;
	}
	return res;
}
signed main()
{
	int n;
	cin>>n;
	cout<<(n+1)*qp(4,mod-2)%mod<<endl;
	return 0;
}
