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
const int N=200005;
int n,m,l,r;
int lt[N],rt[N],c[N],cnt[N];
char s[3][N];
int find(int x){
	while(x!=lt[x]) x=lt[x]=lt[lt[x]];
	return lt[x];
}
int find1(int x){
	while(x!=c[x]) x=c[x]=c[c[x]];
	return c[x];
}
int main()
{
//	freopen("go.in","r",stdin);
//	freopen("go.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%s%s",s[1]+1,s[2]+1);
	for(int i=0;i<=n+n;++i) lt[i]=rt[i]=c[i]=i;
	for(int i=2;i<=n;++i){
		if(s[1][i-1]!='X'&&s[1][i]!='X'){
			int u=find(i-1),v=find(i);
			lt[v]=u;
			rt[u]=i;
		}
		if(s[2][i-1]!='X'&&s[2][i]!='X'){
			int u=find(i-1+n),v=find(i+n);
			lt[v]=u;
			rt[u]=i+n;
		}
	}
	for(int i=1;i<=n;++i){
		if(s[1][i]!='X'&&s[2][i]!='X'){
			int u=find(i),v=find(i+n);
			if(find1(u)==find1(v)) continue;
			
			if(cnt[u]>cnt[v]) c[v]=u,cnt[v]=cnt[u]+1;
			else if(cnt[v]<cnt[u]) c[u]=v,cnt[u]=cnt[v]+1;
			else if(u<v-n) c[find1(v)]=find1(u),cnt[v]=cnt[u]+1;
			else c[find1(u)]=find1(v),cnt[u]=cnt[v]+1;
		}
	}
	int l,r,ll,rr,u,v;
	while(m--){
		scanf("%d%d",&l,&r);
		ll=(l>n?l-n:l);
		rr=(r>n?r-n:r);
		if(ll>rr) swap(l,r);
		u=find(l),v=find(r);
		ll=find1(u),rr=find1(v);
//		cout<<"l="<<l<<" r="<<r<<endl;
//		cout<<"u="<<u<<" v="<<v<<endl;
//		cout<<"ll="<<ll<<" rr="<<rr<<endl;
		if(ll!=rr){
			printf("-1\n");
			continue;
		}
		printf("%d\n",(abs(r-l))%n+cnt[v]-cnt[u]);
	}
	return 0;
}
