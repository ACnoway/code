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
const int N=10000007;
int n,m,k;
int a[N],ling[N],yi[N];
int main()
{
	n=read();
	m=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
	}
	for(int i=1;i<=n;++i){
		yi[i]=yi[i-1];
		ling[i]=ling[i-1];
		if(a[i]) ++yi[i];
		else ++ling[i];
	}
	int st=1,en=0,cnt=1;
	for(int i=1;i<=n;++i){
		if(i-st+1>m){
			i=en;
			st=en+1;
			++cnt;
			continue;
		}
		if(abs((ling[i]-ling[st-1])-(yi[i]-yi[st-1]))<=k||(ling[i]-ling[st-1])*(yi[i]-yi[st-1])==0) en=i;
	}
	if(en!=n) ++cnt;
	printf("%d\n",cnt);
	return 0;
}
