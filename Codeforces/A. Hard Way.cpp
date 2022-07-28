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
	int t=read();
	while(t--){
		int x1=read(),y1=read(),x2=read(),y2=read(),x3=read(),y3=read();
		if(y1==y2&&y1>y3){
			write(abs(x1-x2));
			putchar('\n');
		}
		else if(y1==y3&&y1>y2){
			write(abs(x1-x3));
			putchar('\n');
		}
		else if(y3==y2&&y3>y1){
			write(abs(x2-x3));
			putchar('\n');
		}
		else{
			putchar('0');
			putchar('\n');
		}
	}
	return 0;
}