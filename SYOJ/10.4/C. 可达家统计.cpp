#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<bitset>
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
const int N=3003;
int n;
string s[N];
int ru[N],q[N*N],h,t,a[N],cnt;
bitset<N> f[N];
inline void tuopu(){
	for(int i=0;i<n;++i){
		if(!ru[i]) q[++t]=i;
	}
	int u;
	while(h<t){
		u=q[++h];
		a[++cnt]=u;
		for(int i=0;i<n;++i){
			if(s[u][i]=='1'){
				--ru[i];
				if(!ru[i]) q[++t]=i;
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>n;
	for(int i=0;i<n;++i){
		cin>>s[i];
		for(int j=0;j<n;++j){
			if(s[i][j]=='1') ++ru[j];
		}
	}
	tuopu();
	int u;
	for(int i=n;i;--i){
		u=a[i];
		f[u][u]=1;
		for(int j=0;j<n;++j){
			if(s[u][j]=='1'){
				f[u]|=f[j];
			}
		}
	}
	int ans=0;
	for(int i=0;i<n;++i) ans+=f[i].count();
	cout<<ans<<endl;
	return 0;
}
