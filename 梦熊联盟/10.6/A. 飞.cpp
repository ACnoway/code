#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<queue>
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
const int N=20004;
int n,m;
int p[N];
typedef pair<int,int> pii;
pii a[N];
priority_queue<int,vector<int>,greater<int> > q;
int main()
{
	freopen("fly.in","r",stdin);
	freopen("fly.out","w",stdout);
	n=read();
	m=read();
	for(int i=1;i<=n;++i) p[i]=read();
	for(int i=1;i<=m;++i) a[i].first=read(),a[i].second=read();
	sort(p+1,p+n+1);
	sort(a+1,a+m+1);
	int ans=0,st=1;
	for(int i=1;i<=n;++i){
		while(st<=m&&a[st].first<=p[i]) q.push(a[st++].second);
		while(!q.empty()&&q.top()<p[i]) q.pop();
		if(!q.empty()) ++ans,q.pop();
	}
	printf("%d\n",ans);
	return 0;
}
