#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<climits>
using namespace std;
long long read(){
	long long x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<3ll)+(x<<1ll)+(c^48);
		c=getchar();
	}
	return x*f;
}
const int N=102;
const long long inf=LONG_LONG_MAX;
int T,n,h,t,cur;
long long a[N][N],f[1003][N][N],da[2][N];
long long ma,ans,m;
int main()
{
	T=(int)read();
	while(T--){
		n=(int)read();
		m=read();
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				a[i][j]=read();
				f[0][i][j]=f[1][i][j]=0;
			}
			da[0][i]=da[1][i]=0;
		}
		ma=ans=0;
		cur=0;
		for(int ti=1;ti<=m;++ti){
			for(int i=1;i<=n;++i){
				for(int j=1;j<=n;++j){
					f[ti][i][j]=max(f[ti][i][j],da[cur][i]+a[i][j]);
					da[cur^1][j]=max(da[cur^1][j],f[ti][i][j]);
					ma=max(ma,f[ti][i][j]);
				}
				da[cur][i]=0;
			}
			cur^=1;
			if(ma>=m){
				ans=ti;
				break;
			}
		}
		if(ans!=inf) printf("%lld\n",ans);
		else printf("-1\n");
	}
	return 0;
}
