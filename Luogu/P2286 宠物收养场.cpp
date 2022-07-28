#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#define int long long
using namespace std;
const int MOD=1000000;
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
inline int Rand(){
	static unsigned long long r=2333;
	return (r*=233333)%=2147483647;
}
struct node
{
	node* ch[2];
	int val,kind,pri;
	node(int v,int k): val(v),kind(k) {pri=Rand();ch[0]=ch[1]=nullptr;}

};
typedef node* tree;
tree t=nullptr;
int n,sum,kk,vv;
void rotate(tree &p,int d){
	tree k=p->ch[d^1];
	p->ch[d^1]=k->ch[d];
	k->ch[d]=p;
	p=k;
}
void ins(tree &p,int v,int k){
	if(!p){
		p=new node(v,k);
		return;
	}
	int d=(v<p->val?0:1);
	ins(p->ch[d],v,k);
	if(p->ch[d]->pri<p->pri) rotate(p,d^1);
}
void del(tree &p,int v){
	if(!p) return;
	if(v==p->val){
		if(!p->ch[0]&&!p->ch[1]){
			p=nullptr;
			return;
		}
		else if(!p->ch[0]){
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
			int d=(p->ch[0]->pri<p->ch[1]->pri?1:0);
			rotate(p,d);del(p->ch[d],v);
		}
	}
	else if(v<p->val) del(p->ch[0],v);
	else del(p->ch[1],v);
}
tree nxt(tree p,int x,tree now){
	if(!p) return now;
	if(x==p->val) return p;
	int cha=abs(p->val-x),chan=abs(now->val-x);
	if(p->val<x){
		if(cha<=chan) return nxt(p->ch[1],x,p);
		else return nxt(p->ch[1],x,now);
	}
	else{
		if(cha<chan) return nxt(p->ch[0],x,p);
		else return nxt(p->ch[0],x,now);
	}
}
signed main()
{
	n=read();
	while(n--){
		kk=read();vv=read();
		if(!t){
			ins(t,vv,kk);
			continue;
		}
		if(t->kind==kk) ins(t,vv,kk);
		else{
			tree temp=nxt(t,vv,t);
			if(temp){
				sum+=abs(temp->val-vv);
				del(t,temp->val);
			}
		}
	}
	write(sum%MOD);
	return 0;
}