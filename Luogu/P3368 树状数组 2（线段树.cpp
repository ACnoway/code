//线段树开四倍数组！！！！！
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
struct node
{
	int l,r,sum,num;
}t[3000006];
int a[1000005];
inline void build(int i,int l,int r){
	t[i].l=l;t[i].r=r;
	t[i].num=0;
	if(l==r){
		t[i].sum=a[l];
		return;
	}
	int mid=(l+r)>>1;
	build(i*2,l,mid);
	build(i*2+1,mid+1,r);
	t[i].sum=t[i*2].sum+t[i*2+1].sum;
}
inline int search(int i,int dis,int ans){
	ans+=t[i].num;
	if(t[i].l==t[i].r){
		return ans+t[i].sum;
	}
	if(dis<=t[i*2].r) return search(i*2,dis,ans);
	if(dis>=t[i*2+1].l) return search(i*2+1,dis,ans);
}
inline void add(int i,int l,int r,int k){
	if(t[i].l>=l&&t[i].r<=r){
		t[i].num+=k;
		return;
	}
	if(t[i*2].r>=l) add(i*2,l,r,k);
	if(t[i*2+1].l<=r) add(i*2+1,l,r,k);
}
int main()
{
	int n,m;
	n=read();m=read();
	for(int i=1;i<=n;++i) a[i]=read();
	build(1,1,n);
	for(int i=0;i<m;++i){
		int op,x;
		op=read();x=read();
		if(op==1){
			int y,k;
			y=read();k=read();
			add(1,x,y,k);
		}
		else{
			write(search(1,x,0));
			putchar('\n');
		}
	}
	return 0;
}