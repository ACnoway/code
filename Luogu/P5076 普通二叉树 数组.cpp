#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int n,op,x,cont;
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
struct node
{
	int data,lchild,rchild,siz,cnt;
}t[10004];
void insertBST(int x,int v){
	t[x].siz++;
	if(v==t[x].data){
		t[x].cnt++;
		return;
	}
	if(v<t[x].data){
		if(t[x].lchild!=0){
			insertBST(t[x].lchild,v);
			return;
		}
		cont++;
		t[cont].data=v;
		t[cont].siz=t[cont].cnt=1;
		t[cont].lchild=t[cont].rchild=0;
		t[x].lchild=cont;
		return;
	}
	if(v>t[x].data){
		if(t[x].rchild!=0){
			insertBST(t[x].rchild,v);
			return;
		}
		cont++;
		t[cont].data=v;
		t[cont].siz=t[cont].cnt=1;
		t[cont].lchild=t[cont].rchild=0;
		t[x].rchild=cont;
		return;
	}
}
int valtork(int x,int v){
	if(!x) return 0;
	if(v<t[x].data) return valtork(t[x].lchild,v);
	if(v==t[x].data) return t[t[x].lchild].siz;
	return valtork(t[x].rchild,v)+t[t[x].lchild].siz+t[x].cnt;
}
int rktoval(int x,int rk){
	if(!x) return 0;
	if(t[t[x].lchild].siz>=rk) return rktoval(t[x].lchild,rk);
	if(t[t[x].lchild].siz+t[x].cnt>=rk) return t[x].data;
	return rktoval(t[x].rchild,rk-t[t[x].lchild].siz-t[x].cnt);
}
int qian(int x,int v,int ans){
	if(!x) return ans;
	if(t[x].data==v){
		int s=t[x].lchild;
		int p=t[s].data;
		while(t[s].rchild){
			s=t[s].rchild;
			p=t[s].data;
		}
		return max(ans,p);
	}
	if(t[x].data>v) return qian(t[x].lchild,v,ans);
	if(t[x].data<v) return qian(t[x].rchild,v,max(ans,t[x].data));
}
int hou(int x,int v,int ans){
	if(!x) return ans;
	if(t[x].data==v){
		int s=t[x].rchild;
		int p=t[s].data;
		while(t[s].lchild){
			s=t[s].lchild;
			p=t[s].data;
		}
		return min(ans,p);
	}
	if(t[x].data>v) return hou(t[x].lchild,v,min(ans,t[x].data));
	if(t[x].data<v) return hou(t[x].rchild,v,ans);
}
int main()
{
	t[0].data=t[0].lchild=t[0].rchild=t[0].siz=t[0].cnt=0;
	n=read();
	for(int i=0;i<n;++i){
		op=read();x=read();
		switch(op){
			case 1:{
				write(valtork(1,x)+1);
				putchar('\n');
				break;
			}
			case 2:{
				write(rktoval(1,x));
				putchar('\n');
				break;
			}
			case 3:{
				write(qian(1,x,-INF));
				putchar('\n');
				break;
			}
			case 4:{
				write(hou(1,x,INF));
				putchar('\n');
				break;
			}
			case 5:{
				if(cont==0){
					cont++;
					t[cont].cnt=t[cont].siz=1;
					t[cont].data=x;
				}
				else insertBST(1,x);
				break;
			}
		}
	}
	return 0;
}