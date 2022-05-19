#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
inline int read(){
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
inline int Rand()
{
	static unsigned long long r=2333;
	return (r*=233333)%=2147483647;
}
const int inf=1e9+7;
const int maxn=500010;
struct node
{
	node* ch[2];
	int val,pri,siz,cnt;
	node(int v): val(v){siz=cnt=1;pri=Rand();ch[0]=ch[1]=nullptr;}
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
int n,q;
void rotate(tree &p,int d){
	tree k=p->ch[d^1];
	p->ch[d^1]=k->ch[d];
	k->ch[d]=p;
	p->update();k->update();
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
int kth(tree p,int k){
	int ss=(p->ch[1]?p->ch[1]->siz:0);
	if(k<=ss) return kth(p->ch[1],k);
	else if(k<=ss+p->cnt) return p->val;
	else return kth(p->ch[0],k-ss-p->cnt);
}
int main()
{
	n=read();q=read();
	int op,x;
	for(int i=0;i<n;++i){
		x=read();
		ins(rt,x);
	}
	for(int i=0;i<q;++i){
		op=read();x=read();
		if(op==1){
			write(kth(rt,x));
			putchar('\n');
		}
		else ins(rt,x);
	}
	return 0;
}