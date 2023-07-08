#include<iostream>
#include<cstdio>
using namespace std;
const int N=100005;
int n;
double p;
double a[N],b[N],c[N];
int main()
{
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>p;
		a[i]=(a[i-1]+1)*p;
		b[i]=(b[i-1]+2*a[i-1]+1)*p;
		c[i]=c[i-1]+(3*b[i-1]+3*a[i-1]+1)*p;
	}
	printf("%.1lf\n",c[n]);
	return 0;
}
