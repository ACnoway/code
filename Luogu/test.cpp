#include <iostream>
#include <cstdio>
#include <algorithm>
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
struct node
{
	int sum;
	node* ch[2];
	node(int v): sum(v){ch[0]=ch[1]=nullptr;}
	~node(){
		if(ch[0]) delete ch[0];
		if(ch[1]) delete ch[1];
	}
};
node *t=nullptr;
int main()
{
	int a[101];
	a[1]=1123;
	a[100]=1100;
	cout<<a[100];
	return 0;
}