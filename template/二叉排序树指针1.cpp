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
		else if(e</*����Ŀ����ע�����*/p->data){
			p->lchild=s;
		}
		else{
			p->rchild=s;
		}
		return true;
	}
	return false;
}
/*һ��ָ��ָ��a��˫��ָ��p�������˫��ָ��p����ֵ��Ҳ����*p��
��Ȼ��������ָ���ָ��a����һ��ָ�룬������ָ��aָ��Ķ���
*/
bool Delete(Bitree *p){
	Bitree q,s;
	if(!(*p)->lchild&&!(*p)->rchild){
		*p=NULL;
	}
	else if(!(*p)->lchild){
		q=*p;
		//q�Ǹ�ָ�룬������ֵΪ˫��ָ��p��ָ���ָ��
		*p=(*p)->rchild;
		//�ı�
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
		//��p��ֱ��ǰ��
		while(s->rchild){
			q=s;
			s=s->rchild;
		}
		(*p)->data=s->data;
		//�жϽ�� p �������� s �Ƿ�������������Ϊ�����������
        if (q != *p) {
            q->rchild = s->lchild;//���У�����ɾ��ֱ��ǰ������ͬʱ����ǰ�������ӽ���Ϊ q ָ����ĺ��ӽ��
        }
        else {
            q->lchild = s->lchild;//����ֱ�ӽ����������Ƽ���
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