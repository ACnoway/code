#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
using namespace std;
const int INF=2147483647;
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
typedef struct BiTNode
{
	int data,siz,cnt;
	struct BiTNode *lchild,*rchild;
}BiTNode,*Bitree;
void insertBST(Bitree *t,int e){
	if(!(*t)){
		Bitree s=new BiTNode;
		s->data=e;
		s->lchild=s->rchild=nullptr;
		s->siz=s->cnt=1;
		(*t)=s;
		return;
	}
	(*t)->siz++;
	if(e==(*t)->data){
		(*t)->cnt++;
		return;
	}
	if(e<(*t)->data){
		insertBST(&(*t)->lchild,e);
		return;
	}
	if(e>(*t)->data){
		insertBST(&(*t)->rchild,e);
		return;
	}
}
int valtork(Bitree t,int x){
	if(!t) return 0;
	if(x==t->data) return (t->lchild?t->lchild->siz:0);
	if(x<t->data) return valtork(t->lchild,x);
	if(x>t->data) return valtork(t->rchild,x)+(t->lchild?t->lchild->siz:0)+t->cnt;
}
int rktoval(Bitree t,int rk){
	if(!t) return -1;
	if((t->lchild?t->lchild->siz:0)>=rk) return rktoval(t->lchild,rk);
	if((t->lchild?t->lchild->siz:0)+t->cnt>=rk) return t->data;
	return rktoval(t->rchild,rk-(t->lchild?t->lchild->siz:0)-t->cnt);
}
int qian(Bitree t,int x,int ans){
	if(!t) return ans;
	if(x==t->data){
		if(!t->lchild) return ans;
		Bitree s=t->lchild;
		int p=s->data;
		while(s->rchild){
			s=s->rchild;
			p=s->data;
		}
		return max(p,ans);
	}
	if(t->data>x) return qian(t->lchild,x,ans);
	if(t->data<x) return qian(t->rchild,x,max(ans,t->data));
}
int hou(Bitree t,int x,int ans){
	if(!t) return ans;
	if(t->data==x){
		if(!t->rchild) return ans;
		Bitree s=t->rchild;
		int p=s->data;
		while(s->lchild){
			s=s->lchild;
			p=s->data;
		}
		return min(ans,p);
	}
	if(t->data>x) return hou(t->lchild,x,min(ans,t->data));
	if(t->data<x) return hou(t->rchild,x,ans);
}
int main()
{
	Bitree t=nullptr;
	int q;
	q=read();
	for(int i=0;i<q;++i){
		int op,x;
		op=read();x=read();
		switch(op){
			case 1:{
				write(valtork(t,x)+1);
				putchar('\n');
				break;
			}
			case 2:{
				write(rktoval(t,x));
				putchar('\n');
				break;
			}
			case 3:{
				write(qian(t,x,-INF));
				putchar('\n');
				break;
			}
			case 4:{
				write(hou(t,x,INF));
				putchar('\n');
				break;
			}
			case 5:{
				insertBST(&t,x);
				break;
			}
		}
	}
	return 0;
}