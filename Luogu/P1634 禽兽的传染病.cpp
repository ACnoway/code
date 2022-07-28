#include <iostream>
#include <cstdio>
using namespace std;
unsigned long long read(){
	unsigned long long x=0,f=1;
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
void write(unsigned long long x){
	if(x<0){x=-x;putchar('-');}
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
int main()
{
	unsigned long long x=read(),n=read(),cnt=1;
	for(int i=1;i<=n;++i){
		cnt+=cnt*x;
	}
	write(cnt);
	return 0;
}