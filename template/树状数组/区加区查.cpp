#include <iostream>
#include <cstdio>
#define ll long long
using namespace std;
int reint(){
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
ll rell(){
	ll x=0;
	int f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
	}
	return x*(ll)f;
}
void write(int x){
	if(x<0){x=-x;putchar('-');}
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
int n,m;
ll a,t[100005],t1[100005];
inline int lowbit(int x){
	return x&(-x);
}
inline void add(int x,ll k){
	for(int i=x;i<=n;i+=lowbit(i)) t[i]+=k,t1[i]+=k*(x-1);
}
inline ll query(int x){
	ll ans=0;
	for(int i=x;i;i-=lowbit(i)){
		ans+=x*t[i]-t1[i];
	}
	return ans;
}
int main()
{
	n=reint();
	m=reint();
	ll last=0;
	for(int i=1;i<=n;++i){
		a=rell();
		add(i,a-last);
		last=a;
	}
	for(int i=0;i<m;++i){
		int op=reint(),x=reint(),y=reint();
		if(op==1){
			ll k=rell();
			add(x,k);
			add(y+1,-k);
		}
		else{
			cout<<query(y)-query(x-1)<<endl;
		}
	}
	return 0;
}