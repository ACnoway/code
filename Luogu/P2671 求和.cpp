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
const int P=10007;
int num[100005],col[100005],xz[100005];
int n,m,ans;
int main()
{
	n=read();
	m=read();
	for(int i=1;i<=n;++i) num[i]=read();
	for(int i=1;i<=n;++i) col[i]=read();
	for(int i=2;i<=n;++i){
		
	}
	for(int i=1;i<n;++i){
		for(int j=i+2;j<=n;j+=2){
			if(col[i]==col[j]){
				ans=(ans%P+(((i%P+j%P)%P)*((num[i]%P+num[j]%P)%P))%P)%P;
			}
		}
	}
	write(ans);
	return 0;
}