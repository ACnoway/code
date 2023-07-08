#include<iostream>
#include<cstdio>
#include<cmath>
#define int long long
using namespace std;
const int N=300005;
int n,cnt,ans;
char ch;
double a[N],b[N],c[N];
signed main()
{
	cin>>n;
	for(int i=1;i<=n;++i){
		ch=getchar();
		if(ch=='1') a[i]=0.0;
		else if(ch=='?') a[i]=0.5;
		else a[i]=1.0;
        //算概率，从一次推到二次
		b[i]=(b[i-1]+1)*a[i];
		c[i]=c[i-1]+(b[i-1]*2+1)*a[i];
	}
	printf("%.4lf\n",c[n-1]);
	return 0;
} 
