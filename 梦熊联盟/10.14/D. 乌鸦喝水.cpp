#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#define int long long
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
const int N=502;
int a,b,n,m;
int d[N][N];
signed main()
{
	freopen("pirate.in","r",stdin);
	freopen("pirate.out","w",stdout);
	a=read(),b=read();
	n=read(),m=read();
	int flag=0;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			d[i][j]=read();
			if(d[i][j]!=d[1][1]) ++flag;
		}
	}
	if(a>b) swap(a,b);
	a=min(a,min(n,m));
	b=min(b,max(n,m));
	if(!flag){
		if(n*m==a*b){
			printf("1145141919810\n");
			return 0;
		}
		printf("%lld\n",(int)ceil((double)(n*m*d[1][1])/(double)(n*m-a*b)-1.0)*a*b);
	}
	else{
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				for(int x=1;x<=a;++x){
					for(int y=1;y<=b;++y){
						
					}
				}
			}
		}
	}
	return 0;
}
