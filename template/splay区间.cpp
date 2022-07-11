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
		//tag表示以该节点为根的中序遍历是否被翻转了
		node(int value,node *f,node **rt):
			val(value),fa(f),root(rt)
			{ch[0]=ch[1]=nullptr;siz=cnt=1;tag=0;}

		//维护节点siz
		void maintain(){
			siz=cnt;
			if(ch[0]) siz+=ch[0]->siz;
			if(ch[1]) siz+=ch[1]->siz;
		}
		//当前节点与父节点的关系
		//是左孩子还是右孩子
		int relation(){
			return this==fa->ch[1];
		}
		//返回当前节点的祖父（我不要RE啊啊啊
		node *grandpa(){
			return fa?fa->fa:nullptr;
		}
		
	};
}
int main()
{

	return 0;
}