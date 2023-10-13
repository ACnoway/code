#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
inline int read(){
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
const int N=2003,M=50004;
int n,m;
int match[N];
bool st[N],mp[N][N];
bool find(int x){
	for(int v=0;v<m;++v){
		if(!st[v]&&mp[x][v]){
			st[v]=1;
			if(match[v]==-1||find(match[v])){
				match[v]=x;
				return 1;
			}
		}
	}
	return 0;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	while(cin>>n){
		int x,y,k;
		m=n;
		for(int i=0;i<N;++i){
			for(int j=0;j<N;++j) mp[i][j]=0;
		}
		for(int i=1;i<=n;++i){
			cin>>x>>k;
			for(int j=1;j<=k;++j){
				cin>>y;
				mp[x][y]=mp[y][x]=1;
			}
		}
		int ans=0;
		for(int i=0;i<N;++i) match[i]=-1;
		for(int i=0;i<n;++i){
			for(int j=0;j<N;++j) st[j]=0;
			if(find(i)) ans++;
		}
		cout<<ans/2<<endl;
	}
	return 0;
}
/*
  4
  0 1 1
  1 2 2 3
  2 0
  3 0
  5
  3 3 1 4 2
  1 1 0
  2 0
  0 0
  4 0
 */
