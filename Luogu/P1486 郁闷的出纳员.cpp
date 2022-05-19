#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#define int long long
using namespace std;
inline int rint(){
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
inline char rchar(){
	char c=getchar();
	while(c<'A'||c>'Z') c=getchar();
	return c;
}
void write(int x){
	if(x<0){x=-x;putchar('-');}
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
inline int Rand(){
	static unsigned long long seed=2333;
	return (seed*=233333)%=2147483647;
}
struct node
{
	node* ch[2];
	int val,pri,siz,cnt;
	node(int x): val(x){siz=cnt=1;pri=Rand();ch[0]=ch[1]=nullptr;}
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
tree t=nullptr;
int n,minm,k,lt,all;
char op;
void rotate(tree &p,int d){
	tree k=p->ch[d^1];
	p->ch[d^1]=k->ch[d];
	k->ch[d]=p;
	p->update();k->update();
	p=k;
}
void ins(tree &p,int x){
	if(!p){
		p=new node(x);
		return;
	}
	if(x==p->val){++p->siz;++p->cnt;return;}
	int d=p->cmp(x);
	ins(p->ch[d],x);
	if(p->ch[d]->pri<p->pri) rotate(p,d^1);
	p->update();
}
void del(tree &p){
	if(!p) return;
	if(!p->ch[0]){
		tree k=p;
		p=p->ch[1];
		delete(k);
	}
	else if(!p->ch[1]){
		tree k=p;
		p=p->ch[0];
		delete(k);
	}
	else{
		int dd=p->ch[0]->pri<p->ch[1]->pri?1:0;
		rotate(p,dd);del(p->ch[dd]);
	}
	if(p) p->update();
}
void up(tree &p,int x){
	if(!p) return;
	up(p->ch[0],x);
	up(p->ch[1],x);
	p->val+=x;
}
void down(tree &p,int x){
	if(!p) return;
	down(p->ch[0],x);
	down(p->ch[1],x);
	if(p->val-x<minm){
		lt+=p->cnt;
		all-=p->cnt;
		del(p);
		if(p) p->update();
		return;
	}
	else{
		p->val-=x;
		return;
	}
}
int kth(tree p,int k){
	int ss=(p->ch[1]?p->ch[1]->siz:0);
	if(k<=ss) return kth(p->ch[1],k);
	else if(k<=ss+p->cnt) return p->val;
	else return kth(p->ch[0],k-ss-p->cnt);
}
signed main()
{
	n=rint();minm=rint();
	while(n--){
		op=rchar();k=rint();
		switch(op){
			case 'I':{
				if(k>=minm){
					ins(t,k);
					++all;
				}
				break;
			}
			case 'A':{
				up(t,k);
				break;
			}
			case 'S':{
				down(t,k);
				break;
			}
			case 'F':{
				if(k>all){
					write(-1);
					putchar('\n');
				}
				else{
					write(kth(t,k));
					putchar('\n');
				}
				break;
			}
		}
	}
	write(lt);
	return 0;
}