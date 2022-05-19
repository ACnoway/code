#include <iostream>
#include <cstdio>
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
	int val,nxt;
}a[100005];
int main()
{
	int m=read(),cnt=0,head=-1;
	for(int i=1;i<=m;++i){
		char c=getchar();
		while(c<'A'||c>'Z') c=getchar();
		switch(c){
			case 'H':{
				int x=read();
				a[cnt].val=x;
				a[cnt].nxt=head;
				head=cnt++;
				cout<<head<<endl;
				break;
			}
			case 'D':{
				int k=read();
				if(k==0) head=a[head].nxt;
				else a[k-1].nxt=a[a[k-1].nxt].nxt;
				cout<<head<<endl;
				break;
			}
			case 'I':{
				int k=read(),x=read();
				a[cnt].val=x;
				a[cnt].nxt=a[k-1].nxt;
				a[k-1].nxt=cnt++;
				cout<<cnt<<endl;
				break;
			}
		}
	}
	for(int i=head;i!=-1;i=a[i].nxt){
		write(a[i].val);
		putchar(' ');
	}
	return 0;
}