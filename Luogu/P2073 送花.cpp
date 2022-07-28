#include<iostream>
#include<cstdio>
#define int long long
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
inline int Rand(){
	static unsigned long long r=2333;
	return (r*=233333)%=2147483647;
}
struct node
{
	node* ch[2];
	int meili,jiage,pri;
	node(int ml,int jg): meili(ml),jiage(jg) {pri=Rand();ch[0]=ch[1]=nullptr;}
};
typedef node* tree;
tree t=nullptr;
int beaut=0,cost=0,op;
void rotate(tree &p,int d){
	tree k=p->ch[d^1];
	p->ch[d^1]=k->ch[d];
	k->ch[d]=p;
	p=k;
}
void ins(tree &p,int ml,int jg){
	if(!p){
		beaut+=ml;cost+=jg;
		p=new node(ml,jg);
		return;
	}
	if(jg<p->jiage){
		ins(p->ch[0],ml,jg);
		if(p->ch[0]->pri<p->pri) rotate(p,1);
	}
	else if(jg>p->jiage){
		ins(p->ch[1],ml,jg);
		if(p->ch[1]->pri<p->pri) rotate(p,0);
	}
	if(p->ch[0]&&(p->ch[0]?p->ch[0]->pri:2147483647)<p->pri) rotate(p,1);
	if(p->ch[1]&&(p->ch[1]?p->ch[1]->pri:2147483647)<p->pri) rotate(p,0);
}
void delgui(tree &p){
	if(!p) return;
	if(p->ch[1]) delgui(p->ch[1]);
	else{
		beaut-=p->meili;
		cost-=p->jiage;
		tree q=p;
		p=p->ch[0];
		delete(q);
	}
}
void delpian(tree &p){
	if(!p) return;
	if(p->ch[0]) delpian(p->ch[0]);
	else{
		beaut-=p->meili;
		cost-=p->jiage;
		tree q=p;
		p=p->ch[1];
		delete(q);
	}
}
signed main()
{
	freopen("P2073_2.in","r",stdin);
	op=read();
	while(op!=-1){
		switch(op){
			case 1:{
				int w=read(),c=read();
				ins(t,w,c);
				break;
			}
			case 2:{
				delgui(t);
				break;
			}
			case 3:{
				delpian(t);
				break;
			}
		}
		op=read();
	}
	write(beaut);putchar(' ');write(cost);
	return 0;
}