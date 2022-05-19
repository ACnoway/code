#include <iostream>
#include <cstdio>
#include <set>
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
set<int> a;
int main()
{
	for(int i=1;i<=10;++i){
		a.insert(i);
	}
	cout<<"set±éÀú:"<<endl;
	for(set<int>::iterator t=a.begin();t!=a.end();t++) cout<<"   "<<*t<<endl;
	cout<<endl;
	cout<<*a.begin()<<endl<<endl;
	cout<<*a.erase(++++++++++++a.begin())<<endl;
	cout<<"set±éÀú:"<<endl;
	for(set<int>::iterator t=a.begin();t!=a.end();t++) cout<<"   "<<*t<<endl;
	return 0;
}