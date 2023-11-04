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
const int N=10004;
int n;
int c[N],s[N];
int main()
{
	// freopen("random.in","r",stdin);
	// freopen("random.out","w",stdout);
	n=read();
//	int sum=0,cnt=0;
	c[n]=1;
	for(int i=n-1;i>=0;--i){
		for(int j=i+1;j<=n;++j){
			c[i]+=c[j];
			s[i]+=s[j]+c[j];
		}
	}
	printf("%.6lf\n",(double)s[0]/(double)c[0]);
	return 0;
}
