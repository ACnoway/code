#include<iostream>
#include<cstdlib>
#include<cstdio>
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
const int N=100005,M=18;
int LOG[N],bin[M],n,m,a[N],x,y,k;
int f[N][M];
int gcd(int i,int j)
{
	return !j?i:gcd(j,i%j);
}
signed main ()
{
	n=read();
	m=read();
	bin[0]=1;for (int i=1;i<M;++i)bin[i]=bin[i-1]<<1ll;
	LOG[0]=-1;for (int i=1;i<=n;++i)LOG[i]=LOG[i>>1ll]+1;
	for (int i=1;i<=n;++i) f[i][0]=read();
	for (int i=1;i<M;++i)
		for (int j=1;j+bin[i]-1<=n;++j)
			f[j][i]=gcd(f[j][i-1],f[j+bin[i-1]][i-1]);
//	if(n<=50){
////		for(int i=1;i<=n;++i) a[i]=read();
//		int t1,t2,t3;
//		while(m--){
//			int ans=0;
//			x=read(),y=read(),k=read();
//			int a1=f[x][0],a2=f[x+1][0],a3=f[x+2][0];
//			for(int i=x;i<y;++i){
//				if(i!=x) a1=gcd(a1,f[i-1][0]);
//				a2=f[i+1][0];
//				for(int j=i+1;j<y;++j){
//					if(j!=i+1) a2=gcd(a2,f[j-1][0]);
//					a3=f[j+1][0];
//					for(int k=j+1;k<=y;++k){
//						if(k!=j+1) a3=gcd(a3,f[k-1][0]);
//						t1=gcd(a1,a2);
//						t2=LOG[y-k];
//						t3=gcd(f[k+1][t2],f[y-bin[t2]+1][t2]);
//						t2=gcd(t1,a3);
//						ans=max(ans,gcd(t2,t3));
//					}
//				}
//			}
//			printf("%lld\n",ans);
//		}
//	}
	for (int i=1;i<=m;++i)
	{
		x=read();
		y=read();
		k=read();
		if(k==(y-x+1)){
			int lo=LOG[y-x+1];
			printf ("%lld\n",gcd(f[x][lo],f[y-bin[lo]+1][lo]));
		}
		else printf("1\n");
	}
	return 0;
}

