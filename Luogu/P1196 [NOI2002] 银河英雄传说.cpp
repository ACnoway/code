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
const int N=30004;
int T,x,y,ans;
int a[N],p[N],f[N];
char op;
int find(int n){
	if(p[n]==n)
		return p[n];
	int fn=find(p[n]);
	f[n]+=f[p[n]];
	return p[n]=fn;
}
int main()
{
	cin>>T;
	for(int i=1;i<=30000;++i){
		p[i]=i;
		f[i]=1;
		a[i]=1;
	}
	while(T--){
		cin>>op>>x>>y;
		int xx=find(x),yy=find(y);
		if(op=='M'){
			f[xx]+=a[yy];
			p[xx]=yy;
			a[yy]+=a[xx];
			a[xx]=0;
		}
		if(op=='C'){
			if(xx!=yy) printf("-1\n");
			else printf("%d\n",abs(f[x]-f[y])-1);
		}
	}
	return 0;
}
