#include <iostream>
#include <cstdio>
#define il inline
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
int a[500006],t[500005];
int n,m;
int lowbit(int x){
	return x&(-x);
}
il void add(int x,int k){
	//将受到x影响的节点全部加一遍
	for(;x<=n;x+=lowbit(x)) t[x]+=k;
}
il int query(int x){
	//类似一种前缀和的思想
	//利用二进制一位一位往前推1
	int ans=0;
	for(;x;x-=lowbit(x)) ans+=t[x];
	return ans;
}
int main()
{
	n=read();
	m=read();
	for(int i=1;i<=n;++i) a[i]=read(),add(i,a[i]);
	for(int i=0;i<m;++i){
		int op=read(),x=read(),k=read();
		if(op==1) add(x,k);
		else write(query(k)-query(x-1)),putchar('\n');
	}
	return 0;
}