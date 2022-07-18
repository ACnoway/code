#include<cstdio>
#define int long long
using namespace std;
unsigned a[100005];
inline int abs(int x){
	return x>0?x:(-x);
}
signed main(){
	int n,m,p1,s1,s2;
	scanf("%lld",&n);
	for(int i=1;i<=n;i++) scanf("%u",&a[i]);
	scanf("%lld%lld%lld%lld",&m,&p1,&s1,&s2);
	a[p1]+=s1;
	int hu=0,lg=0;
	for(int i=1;i<m;i++) lg+=a[i]*(m-i);
	for(int i=m+1;i<=n;i++) hu+=a[i]*(i-m);
	if(hu>lg){
		int cha=hu-lg;
		int min=cha,minp=m;
		for(int i=1;i<=m;i++){
			int temp=abs(s2*abs(i-m)-cha);
			if(temp<=min){
				min=temp;
				minp=i;
			}
		}
		printf("%lld",minp);
		return 0;
	}
	else if(hu==lg){
		printf("%lld",m);
		return 0;
	}
	else{
		int cha=lg-hu;
		int min=cha,minp=m;
		for(int i=m;i<=n;i++){
			int temp=abs(s2*abs(i-m)-cha);
			if(temp<=min){
				min=temp;
				minp=i;
			}
		}
		printf("%lld",minp);
		return 0;
	}
}


