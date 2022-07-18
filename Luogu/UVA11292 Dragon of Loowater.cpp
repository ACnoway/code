#include <iostream>
#include <cstdio>
#include <algorithm>
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
int lon[20004],q[20004];
int main()
{
	int n,m;
	n=read();
	m=read();
	while(n&&m){
		for(int i=0;i<n;++i)
			lon[i]=read();
		for(int i=0;i<m;++i)
			q[i]=read();
		if(n>m){
			cout<<"Loowater is doomed!"<<endl;
			n=read();
			m=read();
			continue;
		}
		sort(lon,lon+n);
		sort(q,q+m);
		int l1=0,l2=0,all=0;
		while(l1<n&&l2<m){
			if(q[l2]>=lon[l1]){
				all+=q[l2];
				l1++;
				l2++;
			}
			else{
				l2++;
			}
		}
		if(l1==n){
			write(all);
			putchar('\n');
		}
		else{
			cout<<"Loowater is doomed!"<<endl;
		}
		n=read();
		m=read();
	}
	return 0;
}