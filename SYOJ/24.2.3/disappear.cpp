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
	while(c>='0'||c<='9'){
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
	}
	return x*f;
}
const int N=1003;
int n;
bool a[N][N],b[N][N];
int main()
{
//	freopen("disappear.in","r",stdin);
//	freopen("disappear.out","w",stdout);
	n=read();
	for(int i=1;i<=n;++i){
		for(int j=1;j+i<=n;++j){
			char c=getchar();
			while(c!='0'&&c!='1') c=getchar();
			a[i][j]=(c^48);
		}
	}
	int ans=0;
	for(int i=n-1;i;--i){
		for(int j=1;j+i<=n;++j){
			for(int k=1;k+j+i<=n;++k){
				b[i][j+k]^=a[i+j][k];
			}
		}
	}
}

