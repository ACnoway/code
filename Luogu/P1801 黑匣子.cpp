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
int Rand(){
	static unsigned long long r=2333;
	return (r*=233333)%=2147483647;
}
struct node{
	node *ch[2];
	int siz,cnt,val,pri;
	node(int value): val(value) {siz=cnt=1;pri=Rand();ch[0]=ch[1]=nullptr;}
	int cmp(int x){
		if(x==val) return -1;
		return x<val?0:1;
	}
	void update(){
		siz=cnt;
		if(ch[0]) siz+=ch[0]->siz;
		if(ch[1]) siz+=ch[1]->siz;
	}
};
typedef node* tree;
tree rt=nullptr;
void rotate(tree &p,int d){
	tree k=p->ch[d^1];
	p->ch[d^1]=k->ch[d];
	k->ch[d]=p;
	p->update();
	k->update();
	p=k;
}
void ins(tree &p,int x){
	if(!p){p=new node(x);return;}
	if(x==p->val){++p->siz;++p->cnt;return;}
	int d=p->cmp(x);
	ins(p->ch[d],x);
	if(p->ch[d]->pri<p->pri) rotate(p,d^1);
	p->update();
}
int get(tree p,int k){
	int ss=(p->ch[0]?p->ch[0]->siz:0);
	if(k<=ss) return get(p->ch[0],k);
	else if(k<=ss+p->cnt) return p->val;
	else return get(p->ch[1],k-ss-p->cnt);
}
void order(tree p){
	if(!p) return;
	order(p->ch[0]);
	cout<<p->val<<' ';
	order(p->ch[1]);
}
int m,n,k;
int a[200005],u[200005];
int main()
{
	m=read();
	n=read();
	for(int i=1;i<=m;++i) a[i]=read();
	for(int i=1;i<=n;++i){
		int temp=read();
		u[temp]++;
	}
	for(int i=1;i<=m;++i){
		ins(rt,a[i]);
		if(u[i]){
			while(u[i]--){
				write(get(rt,++k));
				putchar('\n');
			}
		}
	}
	return 0;
}