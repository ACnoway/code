#include <iostream>
#include <cstdio>
#include <climits>
using namespace std;
int read(){
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
struct splay{
	struct node{
		node *ch[2],*fa,**root;
		int val,siz,cnt,tag;
		//tag��ʾ�Ըýڵ�Ϊ������������Ƿ񱻷�ת��
		node(int value,node *f,node **rt):
			val(value),fa(f),root(rt)
			{ch[0]=ch[1]=nullptr;siz=cnt=1;tag=0;}

		//ά���ڵ�siz
		void maintain(){
			siz=cnt;
			if(ch[0]) siz+=ch[0]->siz;
			if(ch[1]) siz+=ch[1]->siz;
		}
		//��ǰ�ڵ��븸�ڵ�Ĺ�ϵ
		//�����ӻ����Һ���
		int relation(){
			return this==fa->ch[1];
		}
		//���ص�ǰ�ڵ���游���Ҳ�ҪRE������
		node *grandpa(){
			return fa?fa->fa:nullptr;
		}
		
	};
}
int main()
{

	return 0;
}