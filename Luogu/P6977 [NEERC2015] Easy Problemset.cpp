#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
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
const int N=22;
int n,k;
int a[N][N],b[N];
int main()
{
	n=read();
	k=read();
	for(int i=1;i<=n;++i){
		b[i]=1;
		a[i][0]=read();
		for(int j=1;j<=a[i][0];++j){
			a[i][j]=read();
		}
	}
	int cnt=0,ans=0,now=0;
	while(cnt<k){
		if(++now>n) now=1;
		if(b[now]>a[now][0]) ans+=50;
		else if(a[now][b[now]]<ans){
			++b[now];
			continue;
		}
		else ans+=a[now][b[now]],++b[now];
		++cnt;
	}
	printf("%d\n",ans);
	return 0;
}
