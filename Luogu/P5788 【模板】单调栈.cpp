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
int st[3000006],a[3000006],ans[3000006];
int n,top;
int main()
{
	n=read();
	for(int i=1;i<=n;++i) a[i]=read();
	for(int i=n;i>0;--i){
		while(top&&a[st[top]]<=a[i]) top--;
		ans[i]=top?st[top]:0;
		st[++top]=i;
	}
	for(int i=1;i<=n;++i){
		write(ans[i]);
		putchar(' ');
	}
	return 0;
}