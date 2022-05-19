#include <iostream>
#include <cstdio>
#include <algorithm>
#define fk (h<t)
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
void write(int x){
	if(x<0){x=-x;putchar('-');}
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
int a[50004],q[50004];
int n,k,r=2,ma,ans;
int main()
{
	n=read();
	k=read();
	for(int i=1;i<=n;++i) a[i]=read();
	sort(a+1,a+n+1);
	a[n+1]=2000000009;
	for(int i=1;i<=n;++i){
		while(a[r]-a[i]<=k) r++;
		q[r]=max(r-i,q[r]);
		ma=max(ma,r[i]);
		ans=max(ans,ma+r-i);
	}
	write(ans);
	return 0;
}