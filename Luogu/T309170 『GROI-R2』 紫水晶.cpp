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
int q,op,n,x;
int main()
{
	q=read();
	while(q--){
		op=read();
		n=read(); x=read();
		if(x<n-1){
			printf("-1\n");
			continue;
		}
		if(op==1){
			for(int i=1;i<=n-2;++i) printf("1 ");
			printf("%d %d\n",x-n+2,x-n+2);
		}
		else{
			for(int i=1;i<n;++i) printf("1 ");
			printf("%d\n",x-n+1);
		}
	}
	return 0;
}
