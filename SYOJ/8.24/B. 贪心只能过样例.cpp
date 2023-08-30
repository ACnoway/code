#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<bitset>
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
const int N=102;
int n;
int l[N],r[N];
bitset<1000006> f[N];
int main()
{
	n=read();
	for(int i=1;i<=n;++i){
		l[i]=read();
		r[i]=read();
	}
	f[0].set(0);
	for(int i=1;i<=n;++i){
		for(int j=l[i];j<=r[i];++j){
			f[i]|=f[i-1]<<(j*j);
		}
	}
	printf("%d\n",f[n].count());
	return 0;
}
