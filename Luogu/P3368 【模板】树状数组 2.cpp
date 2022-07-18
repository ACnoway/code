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
int a,n,m;
int t[500005];
inline int lowbit(int x){
	return x&(-x);
}
inline void add(int x,int k){
	for(;x<=n;x+=lowbit(x)) t[x]+=k;
}
inline int query(int x){
	int ans=0;
	for(;x;x-=lowbit(x)) ans+=t[x];
	return ans;
}
int main()
{
	n=read();
	m=read();
	int last=0;
	for(int i=1;i<=n;++i){
		a=read();
		add(i,a-last);
		last=a;
	}
	for(int i=0;i<m;++i){
		int op=read();
		if(op==1){
			int x=read(),y=read(),k=read();
			add(x,k);
			add(y+1,-k);
		}
		else{
			int x=read();
			write(query(x));
			putchar('\n');
		}
	}
	return 0;
}