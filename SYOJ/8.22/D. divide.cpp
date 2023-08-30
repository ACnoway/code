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
const int N=2003,mod=1e9+7;
int n,m,ans,cnt;
int a[N];
bool w[N];
void dfs(int x){
	if(x>n){
		int tmp=0;
		for(int i=1;i<=n;++i){
			for(int j=i+1;j<=n;++j){
				if(w[i]^w[j]) ++tmp;
			}
		}
		if(tmp>cnt){
			ans=1;
			cnt=tmp;
		}
		else if(tmp==cnt){
			++ans;
			ans%=mod;
		}
		return;
	}
	w[x]=0;
	dfs(x+1);
	w[x]=1;
	dfs(x+1);
}
int main()
{
	n=read();
	m=read();
	for(int i=1;i<=n;++i) a[i]=read();
	if(n<=18){
		dfs(1);
		printf("%d %d",cnt,ans);
	}
	else{
		sort(a+1,a+1+n);
		for(int i=n>>1+1;)
	}
	return 0;
}
