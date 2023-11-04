#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
long long read(){
	long long x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<3ll)+(x<<1ll)+(c^48);
		c=getchar();
	}
	return x*f;
}
long long n;
int main()
{
	n=read();
    if(n==1){
        printf("0\n");
        return 0;
    }
	if(n>10000000){
		printf("%.6lf\n",log(n-1)+1.57721566490153286060651209);
	}
	else{
		double ans=0;
		for(double i=1;i<n;++i){
			ans+=1.0/i;
		}
		printf("%.6lf\n",ans+1);
	}
	return 0;
}
