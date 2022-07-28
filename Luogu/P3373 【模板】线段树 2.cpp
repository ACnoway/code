#include <iostream>
#include <cstdio>
#define int long long
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
	int mlz,plz,sum,l,r;
}t[1000005];
int a[100005];
int n,m,p;
inline void pushdown(int i){
	if(t[i].mlz==1&&t[i].plz==0) return;
	int k1=t[i].mlz,k2=t[i].plz;
	t[i<<1].sum=(t[i<<1].sum*k1+k2*(t[i<<1].r-t[i<<1].l+1))%p;
	t[i<<1|1].sum=(t[i<<1|1].sum*k1+k2*(t[i<<1|1].r-t[i<<1|1].l+1))%p;
	t[i<<1].mlz=(t[i<<1].mlz*k1)%p;
	t[i<<1|1].mlz=(t[i<<1|1].mlz*k1)%p;
	t[i<<1].plz=(t[i<<1].plz*k1+k2)%p;
	t[i<<1|1].plz=(t[i<<1|1].plz*k1+k2)%p;
	t[i].mlz=1;
	t[i].plz=0;
	return;
}
inline void build(int i,int l,int r){
	t[i].l=l;t[i].r=r;
	t[i].mlz=1;
	if(l==r){
		t[i].sum=a[l]%p;
		return;
	}
	int mid=(l+r)>>1;
	build(i<<1,l,mid);
	build(i<<1|1,mid+1,r);
	t[i].sum=(t[i<<1].sum+t[i<<1|1].sum)%p;
	return;
}
inline void add(int i,int l,int r,int k){
	if(t[i].l>r||t[i].r<l) return;
	if(t[i].l>=l&&t[i].r<=r){
		t[i].sum+=((t[i].r-t[i].l+1)*k)%p;
		t[i].plz=(t[i].plz+k)%p;
		return;
	}
	pushdown(i);
	if(t[i<<1].r>=l) add(i<<1,l,r,k);
	if(t[i<<1|1].l<=r) add(i<<1|1,l,r,k);
	t[i].sum=(t[i<<1].sum+t[i<<1|1].sum)%p;
	return;
}
inline void mul(int i,int l,int r,int k){
	if(t[i].l>r||t[i].r<l) return;
	if(t[i].l>=l&&t[i].r<=r){
		t[i].sum=(t[i].sum*k)%p;
		t[i].mlz=(t[i].mlz*k)%p;
		t[i].plz=(t[i].plz*k)%p;
		return;
	}
	pushdown(i);
	if(t[i<<1].r>=l) mul(i<<1,l,r,k);
	if(t[i<<1|1].l<=r) mul(i<<1|1,l,r,k);
	t[i].sum=(t[i<<1].sum+t[i<<1|1].sum)%p;
	return;
}
inline int search(int i,int l,int r){
	if(t[i].l>r||t[i].r<l) return 0;
	if(t[i].l>=l&&t[i].r<=r) return t[i].sum;
	pushdown(i);
	int s=0;
	if(t[i<<1].r>=l) s+=search(i<<1,l,r);
	if(t[i<<1|1].l<=r) s+=search(i<<1|1,l,r);
	return s%p;
}
signed main()
{
	n=read();
	m=read();
	p=read();
	for(int i=1;i<=n;++i) a[i]=read();
	build(1,1,n);
	for(int i=1;i<=m;++i){
		int op,x,y;
		op=read();
		x=read();y=read();
		if(op==1){
			int k=read();
			mul(1,x,y,k);
		}
		else if(op==2){
			int k=read();
			add(1,x,y,k);
		}
		else{
			write(search(1,x,y));
			putchar('\n');
		}
	}
	return 0;
}