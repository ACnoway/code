#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<map>
#define ll long long
#define int unsigned long long
#define inf 1e18
//#define mod 1000000007
using namespace std;
const int N=200005;
map<int,int> mp;
int n,m,b[40],sum[N][40],hsh,d,ans;

int read(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-') f=-1;c=getchar();}while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+(c^48);c=getchar();}return x*f;}
void write(int x){if(x<0){x=-x;putchar('-');}if(x>9) write(x/10);putchar(x%10+'0');}
int qpow(int a,int b,int mm){int sum=1;while(b){if(b&1)sum=sum*a%mm;a=a*a%mm;b>>=1;}return sum;}

signed main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read(),m=read();
	mp[0]=0;
	for(int i=1;i<=n;i++){
		d=read();
		for(int j=1;j<=m;j++){
			sum[i][j]=sum[i-1][j];
			if((d>>(j-1))&1) sum[i][j]++;
		}
		for(int j=1;j<=m;j++) b[j]=sum[i][j]-sum[i][j-1];
		b[1]=sum[i][1]-sum[i][m];
		hsh=0;
		for(int j=1;j<=m;j++) hsh=131*hsh+b[j];
		if(mp.find(hsh)==mp.end()) mp[hsh]=i;
		else ans=max(ans,i-mp[hsh]);
	}
	printf("%lld\n",ans);
	
	return 0;
}
