#include <iostream>
#include <cstdio>
using namespace std;
char c;
string read(){
	string x="";
	bool f=0;
	c=getchar();
	while(c<'0'||c>'9'&&c!='}'){
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		f=1;
		x+=c;
		c=getchar();
	}
	if(f) return x;
	else return "-1";
}
string zhuan(string a){
	unsigned long long need=0;
	for(int i=0;i<a.size();++i) need=(need<<3)+(need<<1)+(a[i]^48);
	int st[100];
	int top=0;
	string fin="0x";
	while(need){
		st[top++]=need%16;
		need/=16;
	}
	top--;
	for(;top>=0;top--) fin+=(st[top]>=10?st[top]-10+'A':st[top]+'0');
	return fin;
}
int main()
{
	c=getchar();
	putchar(c);
	while(c!='}'){
		string a=read();
		if(a=="-1"){
			putchar('}');
			break;
		}
		string b=zhuan(a);
		if(b.size()<=a.size()) cout<<b<<c;
		else cout<<a<<c;
	}
	return 0;
}