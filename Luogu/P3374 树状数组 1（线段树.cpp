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
	int l,r,sum;
}t[2000005];
int a[500005];
inline void build(int i,int l,int r){
	t[i].l=l;t[i].r=r;
	if(l==r){
		t[i].sum=a[l];
		return;
	}
	int mid=(l+r)>>1;
	build(i*2,l,mid);
	build(i*2+1,mid+1,r);
	t[i].sum=t[i*2].sum+t[i*2+1].sum;
}
inline int search(int i,int l,int r){
	if(t[i].r<l||t[i].l>r) return 0;
	if(t[i].l>=l&&t[i].r<=r) return t[i].sum;
	int s=0;
	if(t[i*2].r>=l) s+=search(i*2,l,r);
	if(t[i*2+1].l<=r) s+=search(i*2+1,l,r);
	return s;
}
inline void add(int i,int dis,int k){
	if(t[i].l==t[i].r){
		t[i].sum+=k;
		return;
	}
	if(dis<=t[i*2].r) add(i*2,dis,k);
	else add(i*2+1,dis,k);
	t[i].sum=t[i*2].sum+t[i*2+1].sum;
	return;
}
int main()
{
	int n,m;
	n=read();
	m=read();
	for(int i=1;i<=n;++i) a[i]=read();
	build(1,1,n);
	for(int i=0;i<m;++i){
		int op,x,k;
		op=read();x=read();k=read();
		if(op==1){
			add(1,x,k);
		}
		else{
			write(search(1,x,k));
			putchar('\n');
		}
	}
	return 0;
}