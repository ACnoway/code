#include<iostream>
#include<cstdio>
using namespace std;
int n,m;
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
void us(int x,int now,int data)
{
	if(data+(n-x+1)<m||data>m)
	{
		return;
	}
	if(data==m+1)
	{
		for(int i=1;i<=n;i++)
		{
			if((now>>(i-1))&1)
			{
				cout<<i<<" ";
			}
		}
		cout<<endl;
		return;
	}
	us(x+1,now+(1<<x),data+1);
	us(x+1,now,data);
}
int main()
{
	//scanf("%d%d",&n,&m);
	n=read();
	m=read();
	us(0,0,0);
	return 0;
 }