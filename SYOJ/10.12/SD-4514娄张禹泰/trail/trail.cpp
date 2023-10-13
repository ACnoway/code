#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
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
const long double t=log10(2);
int m;
long double a;
int main()
{
//	freopen("trail.in","r",stdin);
//	freopen("trail.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>m;
	while(m--){
		cin>>a;
		long long tmp=a*t;
		printf("%d\n",(int)pow(10,a*t-tmp));
	}
	return 0;
}
