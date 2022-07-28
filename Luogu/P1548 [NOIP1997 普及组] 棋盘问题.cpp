#include <iostream>
#include <cstdio>
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
int main()
{
	int n=read(),m=read();
	int ans1=0,ans2=0;
	for(int i=1;i<=n&&i<=m;++i) ans1+=(n-i+1)*(m-i+1);
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			if(i==j) continue;
			ans2+=(n-i+1)*(m-j+1);
		}
	}
	write(ans1);
	putchar(' ');
	write(ans2);
	return 0;
}