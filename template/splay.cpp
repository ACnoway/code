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
		//���캯��
		node(int value,node *parent,node **root):
			val(value),parent(parent),root(root)
			{ch[0]=ch[1]=nullptr;siz=cnt=1;}

		int relation(){//���ӻ����Һ���
			return this==parent->ch[0]?0:1;
		}

		void maintain(){//ά��size
			siz=cnt;
			if(ch[0]) siz+=ch[0]->siz;
			if(ch[1]) siz+=ch[1]->siz;
		}
		void rotate(){
		//��ת�����������������ݵ�ǰ�ڵ����ĸ��������ж�
			node *old=parent;
			int r=relation();

			//ά���Լ��ĸ��ڵ�
			parent=old->parent;
			if(old->parent){
				//������游��ά���游�ĺ��ӣ����Լ��İֻ����Լ�
				old->parent->ch[old->relation()]=this;
			}
			parent=old->parent;//�����游�ڵ�
			
			//�Լ��ĺ��Ӵ����Լ���λ��
			old->ch[r]=ch[r^1];
			if(ch[r^1]){
				ch[r^1]->parent=old;
				//ά�����ӵĸ��ڵ�
			}
			ch[r^1]=old;
			//���Լ������Լ�����

			old->parent=this;//ά���Լ��ֵĸ��ڵ�
			
			old->maintain();
			maintain();

			if(!parent){
				//ά��ָ�����ָ�룬
				//�����ǰָ��û�и��ڵ㣬��ǰָ��Ϊ��
				*root=this;
			}
		}

		//����Ҫ��splay����
		//       �βγ�ʼ������û���β����β�Ĭ��Ϊ�Ⱥź����
		node *splay(node **target=nullptr){
			if(!target) target=root;
			//�ı����target������this
			//û���β�ʱ��target����root
			//����ָ��rootָ���ĸ�ָ��target��ָ���ĸ�ָ��
			while(this!=*target){
				if(parent==*target){
					//������ڵ���Ŀ��ڵ����ת�Լ�һ��
					rotate();
				}
				else if(relation()==parent->relation()){
					//һ���ͣ�����ת���ڵ㣬����ת�Լ�
					parent->rotate();
					rotate();
				}
				else{
					//֮���Σ���ת�Լ�����
					rotate();
					rotate();
				}
			}
			return *target;
		}

		node *pred(){//ֱ��ǰ��
			node *v=ch[0];//�����������ҵ�����
			while(v->ch[1]) v=v->ch[1];
			return v;
		}

		node *succ(){//ֱ�Ӻ��
			node *v=ch[1];//�����������������
			while(v->ch[0]) v=v->ch[0];
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
		//vֻ����˫��ָ�룡����
		//vָ���ָ���ı䣬�õ�ָ���RE
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

		//splay֮��vָ���ָ����ܲ������²���Ľڵ�
		(*v)->splay();
		//ֱ�ӷ��ظ�
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
		��ǰ����ת�����ڵ㣬�����ת��ǰ�����Һ���
		�����Ļ�ǰ���ͺ���м�ֻ��Ҫ�ҵĽڵ�x

		pre
		   \
		   nxt
		  /
		 x

		 ��Ϊǰ����С��x�����ģ�����Ǵ���x����С��
		 �������Ļ� pre<x<nxt ��û������x����
		 ���ݶ��������������ʣ���ת��x�ں�̽ڵ��������ΪҶ�ڵ�
		 ֱ��ɾ��x����
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

		//ά��size����Ϊɾ��xӰ���ֻ��ǰ���ͺ�̣�����ֻ��ά��
		//ǰ���ͺ�̵�size�Ϳ���
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
			//����������뵽�����Ϊһ����ʱ�ڵ�
			//ֱ�Ӳ��������ʱ�ڵ��ǰ���Ϳ�����
			v=insert(x);
			int res=v->pred()->val;
			erase(v);//�ǵ����ɾ����ʱ�ڵ�
			return res;
		}
		else{
			return v->pred()->val;
		}
	}

	int succ(int x){
		node *v=find(x);
		if(!v){
			//����������뵽�����Ϊһ����ʱ�ڵ�
			//ֱ�Ӳ��������ʱ�ڵ�ĺ�̾Ϳ�����
			v=insert(x);
			int res=v->succ()->val;
			erase(v);//�ǵ����ɾ����ʱ�ڵ�
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
			//v�Ѿ��Ǹ��ˣ�ֱ�Ӳ���������С����
			int res=v->rank();
			erase(v);//ɾ����ʱ�ڵ�
			return res;
		}
		else{
			return v->rank();
		}
	}

	int kth(int k){

		node *v=root;
		while(!(k>=v->rank()&&k<v->rank()+v->cnt)){
			//��k���ǵ�ǰ�ڵ������ʱ
			if(k<v->rank()){
				//Ҫ���k�ȵ�ǰ�ڵ������С��ȥ��������
				v=v->ch[0];
			}
			else{
				//�����ڵݹ��kth(v,k-v->rank()-v->cnt)
				k-=v->rank()+v->cnt;
				v=v->ch[1];
			}
		}
		v->splay();
		return v->val;
	}
} splay;
int main()
{
	int n;
	n=read();
	while(n--){
		int op,x;
		op=read();x=read();
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
				write(splay.rank(x));
				putchar('\n');
				break;
			}
			case 4:{
				write(splay.kth(x));
				putchar('\n');
				break;
			}
			case 5:{
				write(splay.pred(x));
				putchar('\n');
				break;
			}
			case 6:{
				write(splay.succ(x));
				putchar('\n');
				break;
			}
		}
	}
	return 0;
}