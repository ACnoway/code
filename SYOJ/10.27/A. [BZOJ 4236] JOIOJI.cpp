#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#define int long long
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
const int N=200005;
int n;
struct node{
	int a,b,p;
	bool operator <(const node &x)const{
		return a<x.a||(a==x.a&&b<x.b)||(a==x.a&&b==x.b&&p<x.p);
	}
}v[N];
string s;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>s;
	for(int i=0;i<n;++i){
		if(s[i]=='J'){
			v[i+1].a=v[i].a-1;
			v[i+1].b=v[i].b-1;
		}
		else if(s[i]=='O'){
			v[i+1].a=v[i].a+1;
			v[i+1].b=v[i].b;
		}
		else if(s[i]=='I'){
			v[i+1].a=v[i].a;
			v[i+1].b=v[i].b+1;
		}
		v[i+1].p=i+1;
	}
	sort(v,v+n+1);
	int ans=0,now=v[0].p;
	for(int i=1;i<=n;++i){
		if(v[i].a==v[i-1].a&&v[i].b==v[i-1].b) ans=max(ans,v[i].p-now);
		else now=v[i].p;
	}
	printf("%lld\n",ans);
	return 0;
}
