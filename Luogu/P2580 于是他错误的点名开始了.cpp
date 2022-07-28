#include <iostream>
#include <cstdio>
#include <unordered_map>
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
unordered_map<string,int> ma;
int n,m;
int main()
{
	cin>>n;
	for(int i=0;i<n;++i){
		string temp;
		cin>>temp;
		ma[temp]=1;
	}
	cin>>m;
	for(int i=0;i<m;++i){
		string temp;
		cin>>temp;
		if(ma[temp]==2){
			cout<<"REPEAT\n";
		}
		else if(ma[temp]==1){
			cout<<"OK\n";
			ma[temp]=2;
		}
		else{
			cout<<"WRONG\n";
		}
	}
	return 0;
}