#include<iostream>
#include<algorithm>
#define mod 1000000007
#define int long long
using namespace std;
int kd(){
	int x=0,f=1;
	char a=getchar();
	while(a<'0'||a>'9'){
		if(a=='-'){
			f=-1;
		} 
		a=getchar();
	}
	while(a>='0'&&a<='9'){
		x=x*10+a-'0';
		a=getchar();
	}
	return x*f;
}
int n;
struct node{
	int a,b;
	int two,three;
	int id;
}r[100010];
bool cmp(node x,node y){
	return x.a<y.a;
}
bool cnp(node x,node y){
	return x.b==y.b?x.id<y.id:x.b<y.b;
}
int ksm(int x,int y){
	int ans=1;
	while(y){
		if(y%2==1){
			ans=ans*x%mod;
		}
		x=x*x%mod;
		y/=2;
	}
	return ans;
}
int ans=0;
struct nod{
	int l,r;
	int sum;
	int tot;
	int lzj;
}tree[400010];
void push_down(int i){
	tree[i*2].sum=tree[i*2].sum*tree[i].lzj%mod;
	tree[i*2+1].sum=tree[i*2+1].sum*tree[i].lzj%mod;
	tree[i*2].lzj=tree[i*2].lzj*tree[i].lzj%mod;
	tree[i*2+1].lzj=tree[i*2+1].lzj*tree[i].lzj%mod;
	tree[i].lzj=1;
}
void build(int i,int l,int r){
	tree[i].l=l;
	tree[i].r=r;
	tree[i].lzj=1;
	tree[i].sum=0;
	tree[i].tot=0;
	if(l==r){
		return ;
	}
	int mid=(l+r)/2;
	build(i*2,l,mid);
	build(i*2+1,mid+1,r);
	return ;
}
int searchtot(int i,int l,int r){
	if(tree[i].l>=l&&tree[i].r<=r){
		return tree[i].tot;
	}
	push_down(i);
	int s=0;
	if(tree[i*2].r>=l){
		s+=searchtot(i*2,l,r);
	}
	if(tree[i*2+1].l<=r){
		s+=searchtot(i*2+1,l,r);
	}
	return s;
}
void addsum(int i,int p,int k){
	if(tree[i].l==tree[i].r){
		tree[i].sum=k;
		return ;
	}
	push_down(i);
	if(tree[i*2].r>=p){
		addsum(i*2,p,k);
	}
	else{
		addsum(i*2+1,p,k);
	}
	tree[i].sum=(tree[i*2].sum+tree[i*2+1].sum)%mod;
}
int searchsum(int i,int l,int r){
	if(tree[i].l>=l&&tree[i].r<=r){
		return tree[i].sum;
	}
	push_down(i);
	int s=0;
	if(tree[i*2].r>=l){
		s=(s+searchsum(i*2,l,r))%mod;
	}
	if(tree[i*2+1].l<=r){
		s=(s+searchsum(i*2+1,l,r))%mod;
	}
	return s;
}
void addtot(int i,int p){
	if(tree[i].l==tree[i].r){
		tree[i].tot=1;
		return ;
	}
	push_down(i);
	if(tree[i*2].r>=p){
		addtot(i*2,p);
	}
	else{
		addtot(i*2+1,p);
	}
	tree[i].tot=tree[i*2].tot+tree[i*2+1].tot;
}
void cheng(int i,int l,int r){
	if(l>r){
		return ;
	}
	if(tree[i].l>=l&&tree[i].r<=r){
		tree[i].sum=tree[i].sum*2%mod;
		tree[i].lzj=tree[i].lzj*2%mod;
		return ; 
	}
	push_down(i);
	if(tree[i*2].r>=l){
		cheng(i*2,l,r);
	}
	if(tree[i*2+1].l<=r){
		cheng(i*2+1,l,r);
	}
	tree[i].sum=(tree[i*2].sum+tree[i*2+1].sum)%mod;
}
signed main(){
	n=kd();
	for(int i=1;i<=n;i++){
		r[i].a=kd();r[i].b=kd();
		r[i].two=ksm(2,r[i].a);
		r[i].three=ksm(3,r[i].b);
		r[i].id=i;
	}
	sort(r+1,r+n+1,cnp);
	for(int i=1;i<=n;i++){
		r[i].id=i;
	}
	sort(r+1,r+n+1,cmp);
	build(1,1,n);
	for(int i=1;i<=n;i++){
		int cnt=searchtot(1,1,r[i].id);
		addsum(1,r[i].id,ksm(2,cnt)*r[i].three%mod);
		ans=(ans+searchsum(1,r[i].id,n)*r[i].two%mod)%mod;
		cheng(1,r[i].id+1,n);
		addtot(1,r[i].id);
	}
	cout<<ans;
	return 0;
}