#include<iostream>
#include<cstdio>
#include<cstdlib>
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
typedef struct BiTNode
{
	int data;
	struct BiTNode *lchild, *rchild;
}BiTNode,*Bitree;
bool searchBST(Bitree t,int key,Bitree f,Bitree *p){
	if(!t){
		*p=f;
		return false;
	}
	else if(key==t->data){
		*p=t;
		return true;
	}
	else if(key<t->data){
		return searchBST(t->lchild,key,t,p);
	}
	else{
		return searchBST(t->rchild,key,t,p);
	}
}
bool insertBST(Bitree *t,int e){
	Bitree p=NULL;
	if(!searchBST((*t),e,NULL,&p)){
		Bitree s=(Bitree)malloc(sizeof(BiTNode));
		s->data=e;
		s->lchild=s->rchild=NULL;
		if(!p){
			*t=s;
		}
		else if(e</*依题目条件注意符号*/p->data){
			p->lchild=s;
		}
		else{
			p->rchild=s;
		}
		return true;
	}
	return false;
}
/*一个指向指针a的双重指针p，那这个双重指针p的数值（也就是*p）
自然就是它所指向的指针a，是一个指针，而不是指针a指向的东西
*/
bool Delete(Bitree *p){
	Bitree q,s;
	if(!(*p)->lchild&&!(*p)->rchild){
		*p=NULL;
	}
	else if(!(*p)->lchild){
		q=*p;
		//q是个指针，它被赋值为双重指针p所指向的指针
		*p=(*p)->rchild;
		//改变
		free(q);
	}
	else if(!(*p)->rchild){
		q=*p;
		*p=(*p)->lchild;
		free(q);
	}
	else{
		q=*p;
		s=(*p)->lchild;
		//找p的直接前驱
		while(s->rchild){
			q=s;
			s=s->rchild;
		}
		(*p)->data=s->data;
		//判断结点 p 的左子树 s 是否有右子树，分为两种情况讨论
        if (q != *p) {
            q->rchild = s->lchild;//若有，则在删除直接前驱结点的同时，令前驱的左孩子结点改为 q 指向结点的孩子结点
        }
        else {
            q->lchild = s->lchild;//否则，直接将左子树上移即可
        }
        free(s);
	}
	return true;
}
bool searchdel(Bitree *t,int key){
	if(!(*t)){
		return false;
	}
	else{
		if(key==(*t)->data){
			Delete(t);
			return true;
		}
		else if(key<(*t)->data){
			return searchdel(&(*t)->lchild,key);
		}
		else{
			return searchdel(&(*t)->rchild,key);
		}
	}
}
void order(Bitree t){
	if(t==NULL){
		return;
	}
	order(t->lchild);
	write(t->data);putchar(' ');
	order(t->rchild);
}
int main()
{
	int n;
	n=read();
	Bitree t=NULL;
	for(int i=0;i<n;++i){
		int x;
		x=read();
		insertBST(&t,x);
	}
	order(t);
	return 0;
}