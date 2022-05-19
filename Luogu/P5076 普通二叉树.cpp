#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
using namespace std;
const int inf=2147483647;
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
	struct BiTNode *lchild,*rchild;
	int data,siz,cnt;
}BiTNode,*Bitree;
void update(Bitree &t){t->siz=(t->lchild?t->lchild->siz:0)+(t->rchild?t->rchild->siz:0)+t->cnt;}
void insertBST(Bitree &t,int x){
	if(!t){
		Bitree s=new BiTNode;
		s->data=x;
		s->siz=s->cnt=1;
		s->lchild=s->rchild=nullptr;
		t=s;
		return;
	}
	t->siz++;
	if(x==t->data){
		t->cnt++;
		return;
	}
	if(x<t->data){
		insertBST(t->lchild,x);
		return;
	}
	if(x>t->data){
		insertBST(t->rchild,x);
		return;
	}
}
void DeleteBSTNode (Bitree *Root , int data){
    Bitree p = *Root , parent = NULL , s = NULL;
    if (!p) return;
    if (data > p->data)DeleteBSTNode(&(p->rchild) , data);
    if (data < p->data)DeleteBSTNode(&(p->lchild) , data);
    else{
        //当节点为叶节点时
        if (!p->rchild && !p->lchild)*Root = NULL;
        //只有左子树
        else if (!p->rchild && p->lchild) *Root = p->lchild;
        //只有右子树
        else if (p->rchild && !p->lchild) *Root = p->rchild;
        //左右子树均存在
        else{
            s = p->rchild;
            //s 无左子树
            if (!s->rchild)s->rchild = p->rchild;
            //s 有左子树
            else{
                //在 s 的左子树中找到最小的节点
                while (s->lchild) {
                    //记录下 s 的父节点
                    parent = s;
                    s = s->lchild;
                }
                parent->lchild = s->rchild;
                s->lchild = p->lchild;
                s->rchild = p->rchild;
            }
            *Root = s;
        }   
        delete p;
    }
}
void deleteBST(Bitree &t){
	if(!t->lchild&&!t->rchild){
		t=NULL;
		return;
	}
	Bitree q,s;
	if(!t->lchild){
		q=t;
		t=t->rchild;
		delete q;
		return;
	}
	if(!t->rchild){
		q=t;
		t=t->lchild;
		delete q;
		return;
	}
	q=t;
	s=t->lchild;
	while(s->rchild){
		q=s;
		s=s->rchild;
	}
	t->data=s->data;
	if(q!=t){
		q->rchild=s->lchild;
	}
	else{
		q->lchild=s->lchild;
	}
	delete s;
}
bool Delete(Bitree &p){
	Bitree q,s;
	if(!p->lchild&&!p->rchild){
		p=nullptr;
	}
	else if(!p->lchild){
		q=p;
		p=p->rchild;
		delete q;
	}
	else if(!p->rchild){
		q=p;
		p=p->lchild;
		delete q;
	}
	else{
		q=p;
		s=p->lchild;
		while(s->rchild){
			q=s;
			s=s->rchild;
		}
		p->data=s->data;
        if (q != p) {
            q->rchild = s->lchild;
        }
        else {
            q->lchild = s->lchild;
        }
        delete s;
	}
	return true;
}
bool searchdel(Bitree &t,int key){
	if(!t){
		return false;
	}
	else{
		if(key==t->data){
			if(t->cnt>1){
				t->cnt--;
				t->siz--;
				return true;
			}
			deleteBST(t);
			update(t);
			return true;
		}
		else if(key<t->data){
			if(searchdel(t->lchild,key)){
				update(t);
				return true;
			}
		}
		else{
			if(searchdel(t->rchild,key)){
				update(t);
				return true;
			}
		}
	}
}
int valtork(Bitree t,int x){
	if(!t) return 0;
	if(t->data>x) return valtork(t->lchild,x);
	if(t->data==x) return (t->lchild?t->lchild->siz:0);
	return (t->lchild?t->lchild->siz:0)+t->cnt+valtork(t->rchild,x);
}
int rktoval(Bitree t,int rk){
	if(!t) return 0;
	if(rk<=(t->lchild?t->lchild->siz:0)) return rktoval(t->lchild,rk);
	if(rk<=(t->lchild?t->lchild->siz:0)+t->cnt) return t->data;
	return rktoval(t->rchild,rk-(t->lchild?t->lchild->siz:0)-t->cnt);
}
int qian(Bitree t,int x){
	if(!t) return -inf;
	if(t->data>=x) return qian(t->lchild,x);
	return max(t->data,qian(t->rchild,x));
}
int hou(Bitree t,int x){
	if(!t) return inf;
	if(t->data<=x) return hou(t->rchild,x);
	return min(t->data,hou(t->lchild,x));
}
Bitree t=nullptr;
int n;
int main()
{
	freopen("P3369_2.in","r",stdin);
	freopen("P5076.txt","w",stdout);
	n=read();
	while(n--){
		int op=read(),x=read();
		switch(op){
			case 1:{
				insertBST(t,x);
				break;
			}
			case 2:{
				//DeleteBSTNode(&t,x);
				break;
			}
			case 3:{
				write(valtork(t,x)+1);
				putchar('\n');
				break;
			}
			case 4:{
				write(rktoval(t,x));
				putchar('\n');
				break;
			}
			case 5:{
				write(qian(t,x));
				putchar('\n');
				break;
			}
			case 6:{
				write(hou(t,x));
				putchar('\n');
				break;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}