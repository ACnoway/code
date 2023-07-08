#include<iostream>
#include<cstdio>
using namespace std;
double qpow(double a,int b){
	double res=1.0;
	while(b){
		if(b&1) res*=a;
		a*=a;
		b>>=1;
	}
	return res;
}
int main()
{
	double k,n,m;
	cin>>k>>n>>m;
	double t=n*n*m*m,ans=0;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j)
			ans+=1-qpow(1-(i*(n-i+1)*2-1)*(j*(m-j+1)*2-1)/t,k);
	}
	printf("%.0lf\n",ans);
	return 0;
}
