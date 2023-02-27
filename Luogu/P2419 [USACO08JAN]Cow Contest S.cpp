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
bool t1[105][105],t2[105][105];
int n,m;
int main()
{
	n=read();
	m=read();
	for(int i=0;i<m;++i){
		int a,b;
		a=read();b=read();
		t1[a][b]=1;
		t2[b][a]=1;
	}
	for(int k=1;k<=n;++k){
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				t1[i][j]=(t1[i][j]||(t1[i][k]&&t1[k][j]));
				t2[i][j]=(t2[i][j]||(t2[i][k]&&t2[k][j]));
			}
		}
	}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			t1[i][j]=t1[i][j]||t2[i][j];
	int ans=0;
	for(int i=1;i<=n;++i){
		bool flag=true;
		for(int j=1;j<=n;++j){
			if(i==j) continue;
			if(!t1[i][j]){
				flag=false;
				break;
			}
		}
		if(flag) ans++;
	}
	write(ans);
	return 0;
}