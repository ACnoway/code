//������Ҫ���뵽��������Ҿ�һ���˰��������������������� 
#include<cstdio>
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
int main()
{
	int n,l,r;
	n=read();l=read();r=read();
	if(r-l>=n-1){
		write(n-1);
		return 0;
	}
	for(int i=n-1;i>=0;--i){
		int lt=l-i,rt=r-i;
		if(lt%n>rt%n||lt%n==0){
			write(i);
			return 0;
		}
	}
	/*
	��ѧ��ʽ����
	cin>>n>>l>>r;
	cout<<min(r,l+(n-1-l%n))%n;  //�ȳ��Խ���������n-1���������r����ô�������r mod n���������n-1
	*/
	return 0;
}
