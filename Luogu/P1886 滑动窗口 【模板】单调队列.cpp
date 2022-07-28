#include <iostream>
#include <cstdio>
#define feikong (head<=tail)
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
int a[1000006];
int q[1000006];
int n,k,head=1,tail;
int main()
{
	n=read();k=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
		//维护队首在k之内
		while(feikong&&q[head]<=i-k) head++;
		//维护队尾递增（最小值）
		while(feikong&&a[q[tail]]>=a[i]) tail--;
		//将新元素入队
		q[++tail]=i;
		if(i>=k) write(a[q[head]]),putchar(' ');
	}
	putchar('\n');
	head=1;tail=0;
	for(int i=1;i<=n;++i){
		while(feikong&&q[head]<=i-k) head++;
		while(feikong&&a[q[tail]]<=a[i]) tail--;
		q[++tail]=i;
		if(i>=k) write(a[q[head]]),putchar(' ');
	}
	return 0;
}