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
const int N=1003;
int n,m;
int p[3*N];
inline int find(int x){
	if(p[x]!=x) p[x]=find(p[x]);
	return p[x];
}
int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=0;i<=2*n;++i) p[i]=i;
	char op;
	int x,y;
	while(m--){
		cin>>op>>x>>y;
		if(op=='F') p[find(x)]=find(y);
		else p[find(x+n)]=find(y),p[find(y+n)]=find(x);
	}
	int ans=0;
	for(int i=1;i<=n;++i) if(p[i]==i) ++ans;
	cout<<ans<<endl;
	return 0;
}
