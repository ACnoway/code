#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
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
struct country{
	int p,s;
};
country a[150];
int main()
{
	int n;
	n=read();
	int nt=pow(2,n);
	for(int i=0;i<nt;++i) a[i].s=read(),a[i].p=i;
	for(int i=n-1;i>=1;--i){
		int it=pow(2,i),jt=pow(2,n-i),temp=pow(2,n-i-1);
		for(int j=0;j<it;j+=jt){
			a[j]=(a[j].s>a[j+temp].s)?a[j]:a[j+temp];
		}
	}
	write(((a[0].s>a[nt/2].s)?a[nt/2].p:a[0].p)+1);
	return 0;
}