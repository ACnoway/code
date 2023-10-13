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
const int N=100005;
int n,m;
typedef pair<int,int> pii;
pii a[N],b[N];
signed main()
{
	n=read(); m=read();
	double a1=0.0;
	int a2=0,tmp=0,tmp2=0;
	for(int i=1;i<=n;++i){
		a[i].first=read();
		a[i].second=read();
		if(a[i].second) tmp+=a[i].first;
		else tmp2+=(double)a[i].first;
		a2+=a[i].first;
	}
	for(int i=1;i<=m;++i){
		b[i].second=read();
		b[i].first=read();
	}
	sort(b+1,b+m+1);
	for(int i=m;i;--i){
		if(a2>=b[i].second){
			a2-=b[i].first;
			break;
		}
	}
	a1=(double)(tmp*8)/10.0+(double)tmp2;
	if((double)a2<=a1) printf("%lld.00\n",a2);
	else printf("%.2lf\n",a1);
	return 0;
}
