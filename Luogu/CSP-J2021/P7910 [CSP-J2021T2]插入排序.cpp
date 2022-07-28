#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
struct nums{
	int v,pos;
};
int t[8002];
nums b[8002];
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
bool cmp(nums a,nums b){
	if(a.v!=b.v) return a.v<b.v;
	return a.pos<b.pos;
}
int main()
{
	int n,q;
	n=read();q=read();
	for(int i=1;i<=n;++i){
		b[i].v=read();b[i].pos=i;
	}
	sort(b+1,b+1+n,cmp);
	for(int i=1;i<=n;++i) t[b[i].pos]=i;
	for(int T=1;T<=q;++T){
		int op,x;
		op=read();x=read();
		if(op==1){
			int v;
			v=read();
			b[t[x]].v=v;
			for(int j=n;j>=2;--j){
				if(cmp(b[j],b[j-1])){
					nums temp;
					temp=b[j];
					b[j]=b[j-1];
					b[j-1]=temp;
				}
			}
			for(int j=2;j<=n;++j){
				if(cmp(b[j],b[j-1])){
					nums temp;
					temp=b[j];
					b[j]=b[j-1];
					b[j-1]=temp;
				}
			}
			for(int i=1;i<=n;++i) t[b[i].pos]=i;
		}
		else if(op==2){
			write(t[x]);putchar('\n');
		}
	}
	return 0;
}

