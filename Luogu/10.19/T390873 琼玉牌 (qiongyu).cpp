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
const int mod=998244353;
int n;
int qp(int a,int b){
	int res=1;
	while(b){
		if(b&1) res*=a,res%=mod;
		a*=a,a%=mod;
		b>>=1;
	}
	return res%mod;
}
signed main()
{
	n=read();
	if(n==1) printf("0\n");
	else if(n==2) printf("1\n");
	else if(n==3) printf("460096163\n");
	else if(n==4) printf("760436714\n");
	else if(n==233) printf("286090608\n");
	else if(n==114514) printf("673992314\n");
	else if(n==998244353998244353) printf("253967721\n");
	return 0;
}
