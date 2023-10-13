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
const int N=100005;
int T,n,m,q;
typedef pair<int,int> pii;
typedef pair<int,pii> piii;
piii a[N];
pii b[2][N];
int main()
{
	T=read();
	while(T--){
		n=read(); m=read();
		q=read();
		for(int i=0;i<N;++i) b[0][i]=b[1][i]={0,0};
		for(int i=1;i<=q;++i){
			a[i].first=read();
			a[i].second.first=read();
			a[i].second.second=read();
		}
		for(int i=1;i<=q;++i){
			b[a[i].first][a[i].second.first]={i,a[i].second.second};
		}
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				if(b[0][i].first>b[1][j].first) printf("%d ",b[0][i].second);
				else printf("%d ",b[1][j].second);
			}
			putchar('\n');
		}
	}
	return 0;
}
