#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
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
const int N=500005;
int n,ans,l=1;
typedef pair<int,int> pii;
pii a[N];
int b[N],f[N];
bool cmp(pii a,pii b){
	if(a.first==b.first) return a.second<b.second;
	return a.first>b.first;
}
int main()
{
	n=read();
	for(int i=1;i<=n;++i) a[i].first=read(),a[i].second=read();
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;++i) b[i]=a[i].second;
	int p;
	f[1]=b[1];
	for(int i=2;i<=n;++i){
		if(b[i]>=f[l]) f[++l]=b[i];
		else{
			p=upper_bound(f+1,f+l+1,b[i])-f;
			f[p]=b[i];
		}
	}
	printf("%d\n",l);
	return 0;
}
