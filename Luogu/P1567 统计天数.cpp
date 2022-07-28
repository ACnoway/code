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
inline int max(int a,int b){return a>b?a:b;}
int n,a,last;
int main()
{
	n=read();
	int ans=0,temp=0;
	for(int i=1;i<=n;++i){
		a=read();
		if(a>last) temp+=1;
		else{
			ans=max(ans,temp);
			temp=1;
		}
		last=a;
		cout<<"ans="<<ans<<" temp="<<temp<<endl;
	}
	ans=max(ans,temp);
	write(ans);
	return 0;
}