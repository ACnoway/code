#include<iostream>
#include<vector>
#include<cstdio>
#include<cmath>
#define int long long
using namespace std;
const int N=100005;
int n;
double ans;
double a[N];
bool f[N];
void dfs(int x,int res,double gl){
	if(gl==0.0) return;
	if(x==n+2){
		ans+=res*gl;
		return;
	}
	//Ð´0 
	f[x]=0;
	dfs(x+1,res,gl*a[x]);
	//Ð´1£¬¼ÆËãÖ®Ç°¹±Ï× 
	f[x]=1;
	int cnt=0;
	for(int i=x-1;i>=0;--i){
		if(f[i]) break;
		++cnt;
	}
	dfs(x+1,res+cnt*cnt*cnt,gl-gl*a[x]);
}
signed main()
{
	cin>>n;
	a[0]=0.0,a[n+1]=0.0;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	dfs(0,0,1.0);
	printf("%.1lf\n",ans);
	return 0;
}
