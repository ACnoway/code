#include <iostream>
#include <cstdio>
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
	while(c<'A'||c>'Z')
		c=getchar();
	return c;
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
	int st,ed,pri,siz;
	node(int s,int e): st(s),ed(e){siz=1;pri=Rand();ch[0]=ch[1]=nullptr;}
	int cmp(int stt,int edd){
		if(edd==ed) return stt<st?0:1;
		return edd<ed?0:1;
	}
	void update(){
		siz=1;
		if(ch[0]) siz+=(ch[0]->siz);
		if(ch[1]) siz+=(ch[1]->siz);
	}
};
typedef node* tree;
const int INF=0x3f3f3f;
void rotate(tree &p,int d){
	tree k=p->ch[d^1];
	p->ch[d^1]=k->ch[d];
	k->ch[d]=p;
	p->update();k->update();
	p=k;
}
void ins(tree &p,int x,int y){
	if(!p){
		p=new node(x,y);
		return;
	}
	int d=p->cmp(x,y);
	ins(p->ch[d],x,y);
	if(p->ch[d]->pri<p->pri) rotate(p,d^1);
	p->update();
}
void del(tree &p,int x,int y){
	if(!p) return;
	if(x==p->st&&y==p->ed){
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
			rotate(p,d);del(p->ch[d],x,y);
		}
	}
	else if(y==p->ed){
		int d=(x<p->st?0:1);
		del(p->ch[d],x,y);
	}
	else{
		int d=(y<p->ed?0:1);
		del(p->ch[d],x,y);
	}
	if(p) p->update();
}
tree nxt(tree p,int x){
	if(!p) return nullptr;
	int d=(x<p->ed?0:1);
	if(p->ed==x){
		tree tt=nxt(p->ch[0],x);
		if(!tt) return p;
		if(tt->ed!=p->ed) return p;
		else return (tt->st<p->ed?tt:p);
	}
	else if(d==1) return nxt(p->ch[1],x);
	else{
		tree tt=nxt(p->ch[0],x);
		if(!tt) return p;
		if(p->ed==tt->ed) return p->st<tt->st?p:tt;
		return p->ed<tt->ed?p:tt;
	}
}
tree t=nullptr;
int n;
int main()
{
	n=rint();
	while(n--){
		char c=rchar();
		if(c=='A'){
			int st=rint(),ed=rint(),cnt=0;
			while(1){
				tree temp=nxt(t,st);
				if(temp){
					if(temp->st<=ed){
						del(t,temp->st,temp->ed);
						cnt++;
						if(t) t->update();
					}
					else break;
				}
				else break;
			}
			ins(t,st,ed);
			write(cnt);putchar('\n');
		}
		else{
			//if(t) t->update();
			write((t?t->siz:0));
			putchar('\n');
		}
	}
	return 0;
}