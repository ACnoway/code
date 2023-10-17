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
const int N=20;
int n,sum;
int a[N];
int s[N][N];
int main()
{
	freopen("p.in","r",stdin);
	freopen("p.out","w",stdout);
	n=read();
	sum=read();
	for(int i=1;i<=n;++i) a[i]=i;
	s[0][1]=s[1][1]=s[1][2]=1;
	for(int i=2;i<=n;++i){
		for(int j=1;j<=i+1;++j) s[i][j]=s[i-1][j]+s[i-1][j-1];
	}
	do{
		int tmp=0;
		for(int i=1;i<=n;++i){
			tmp+=a[i]*s[n-1][i];
		}
		if(tmp==sum){
			for(int i=1;i<=n;++i) printf("%d ",a[i]);
			return 0;
		} 
	}while(next_permutation(a+1,a+1+n));
	return 0;
}
