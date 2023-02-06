#include <iostream>
#include <cstdio>
#include <climits>
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
struct splay
{
	struct node
	{
		int val;
		node *ch[2],*parent,**root;
		int siz,cnt;
		//构造函数
		node(int value,node *parent,node **root):
			val(value),parent(parent),root(root)
			{ch[0]=ch[1]=nullptr;siz=cnt=1;}

		int relation(){//左孩子还是右孩子
            if(!parent) return 0;
			return this!=parent->ch[0];
		}

		void maintain(){//维护size
			siz=cnt;
			if(ch[0]) siz+=ch[0]->siz;
			if(ch[1]) siz+=ch[1]->siz;
		}
		void rotate(){
		//旋转（左旋还是右旋根据当前节点是哪个孩子来判断
			node *old=parent;
			int r=relation();

			//维护自己的父节点
			parent=old->parent;
			if(old->parent){
				//如果有祖父，维护祖父的孩子，把自己的爸换成自己
				old->parent->ch[old->relation()]=this;
			}
			
			//自己的孩子代替自己的位置
			old->ch[r]=ch[r^1];
			if(ch[r^1]){
				ch[r^1]->parent=old;
				//维护孩子的父节点
			}
			ch[r^1]=old;
			//让自己爸做自己孩子

			old->parent=this;//维护自己爸的父节点
			
			old->maintain();
			maintain();

			if(!parent){
				//维护指向根的指针，
				//如果当前指针没有父节点，则当前指针为根
				*root=this;
			}
		}

		//最重要的splay！！
		//       形参初始化，若没有形参则形参默认为等号后面的
		node *splay(node **target=nullptr){
			if(!target) target=root;
			//改变的是target而不是this
			//没有形参时，target就是root
			//二重指针root指向哪个指针target就指向哪个指针
			while(this!=*target){
				if(parent==*target){
					//如果父节点是目标节点就旋转自己一次
					rotate();
				}
				else if(relation()==parent->relation()){
					//一字型，先旋转父节点，再旋转自己
					parent->rotate();
					rotate();
				}
				else{
					//之字形，旋转自己两次
					rotate();
					rotate();
				}
			}
			return *target;
		}

		node *pred(){//直接前驱
            this->splay();
			node *v=ch[0];//左子树的最右的子树
			while(v&&v->ch[1]) v=v->ch[1];
            if(v) v->splay();
			return v;
		}

		node *succ(){//直接后继
            this->splay();
			node *v=ch[1];//右子树的最左的子树
			while(v&&v->ch[0]) v=v->ch[0];
            if(v) v->splay();
			return v;
		}

		int rank(){
			return ch[0]?ch[0]->siz:0;
		}
	}*root;

	splay(): root(nullptr)
	{
		insert(INT_MIN);
		insert(INT_MAX);
	}

	node *insert(int x){
		//v只能用双重指针！！！
		//v指向的指针会改变，用单指针会RE
		node **v=&root,*fa=nullptr;
		while((*v)&&(*v)->val!=x){
			fa=*v;
			fa->siz++;
			v=&fa->ch[x>fa->val];
		}
		if(*v){
			(*v)->cnt++;
			(*v)->siz++;
		}
		else{
			(*v)=new node(x,fa,&root);
		}

		//splay之后v指向的指针可能不再是新插入的节点
		(*v)->splay();
		//直接返回根
		return root;
	}

	node *find(int x){
		node *v=root;
		while(v&&v->val!=x) v=v->ch[x>v->val];
		if(v) v->splay();
		return v;
	}

	void erase(node *v){
		node *pred=v->pred(),*succ=v->succ();
		/*
		将前驱旋转到根节点，后继旋转到前驱的右孩子
		这样的话前驱和后继中间只有要找的节点x

		pre
		   \
		   nxt
		  /
		 x

		 因为前驱是小于x且最大的，后继是大于x且最小的
		 那这样的话 pre<x<nxt 且没有其他x满足
		 根据二叉排序树的性质，旋转后x在后继节点的左孩子且为叶节点
		 直接删除x即可
		*/
		pred->splay();
		succ->splay(&pred->ch[1]);

		if(v->cnt>1){
			v->siz--;
			v->cnt--;
		}
		else{
			delete v;
			succ->ch[0]=nullptr;
		}

		//维护size，因为删掉x影响的只有前驱和后继，所以只用维护
		//前驱和后继的size就可以
		succ->siz--;
		pred->siz--;
	}

	void erase(int x){
		node *v=find(x);
		if(!v) return;
		erase(v);
	}

	int pred(int x){
		node *v=find(x);
		if(!v){
			//把这个数插入到树里，作为一个临时节点
			//直接查找这个临时节点的前驱就可以了
			v=insert(x);
			int res=v->pred()->val;
			erase(v);//记得最后删除临时节点
			return res;
		}
		else{
			return v->pred()->val;
		}
	}

	int succ(int x){
		node *v=find(x);
		if(!v){
			//把这个数插入到树里，作为一个临时节点
			//直接查找这个临时节点的后继就可以了
			v=insert(x);
			int res=v->succ()->val;
			erase(v);//记得最后删除临时节点
			return res;
		}
		else{
			return v->succ()->val;
		}
	}

	int rank(int x){
		node *v=find(x);
		if(!v){
			v=insert(x);
			//v已经是根了，直接查左子树大小即可
			int res=v->rank();
			erase(v);//删除临时节点
			return res;
		}
		else{
            v->splay();
			return v->rank();
		}
	}

	int kth(int k){

		node *v=root;
		while(v&&!(k>=v->rank()&&k<v->rank()+v->cnt)){
			//当k不是当前节点的排名时
			if(k<v->rank()){
				//要查的k比当前节点的排名小，去左子树找
				v=v->ch[0];
			}
			else{
				//类似于递归的kth(v,k-v->rank()-v->cnt)
				k-=v->rank()+v->cnt;
				v=v->ch[1];
			}
		}
		if(v) v->splay();
		return v->val;
	}
} splay;
int main()
{
	int n,m,last=0,sum=0;
	n=read();m=read();
	for(int i=0;i<n;++i){
		int o=read();
		splay.insert(o);
	}
	while(m--){
		int op,x;
		op=read();x=read();
		x^=last;
		switch(op){
			case 1:{
				splay.insert(x);
				break;
			}
			case 2:{
				splay.erase(x);
				break;
			}
			case 3:{
				last=splay.rank(x);
				break;
			}
			case 4:{
				last=splay.kth(x);
				break;
			}
			case 5:{
				last=splay.pred(x);
				break;
			}
			case 6:{
				last=splay.succ(x);
				break;
			}
		}
		if(op>=3) sum^=last;
	}
	write(sum);
	return 0;
}