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
typedef long long ll;
const int N=2000006;
const ll mod=998244353,base=131;
int n;
int pre[N],LG[N];
string s;
inline ll qujian(int l,int r){
	return (pre[r]+mod-pre[l-1]*LG[r-l+1]%mod)%mod;
}
inline ll sum(int l,int r,int k){
	return (qujian(l,k-1)*LG[r-k]%mod+qujian(k+1,r))%mod;
}
int main()
{
	cin>>n;
	if(!(n&1)){
		cout<<"NOT POSSIBLE"<<endl;
		return 0;
	}
	cin>>s;
	LG[0]=1;
	for(int i=1;i<=n;++i){
		LG[i]=LG[i-1]*base%mod;
		pre[i]=pre[i-1]*base%mod+(s[i-1]-'A')%mod;
		pre[i]%=mod;
	}
	int mid=(n+1)>>1;
	ll a=qujian(1,mid-1),b,ans=0;
	int flag=0;
	for(int i=mid;i<=n;++i){
		b=sum(mid,n,i);
		if(a==b){
			++ans;
			flag=1;
			break;
		}
	}
	b=qujian(mid+1,n);
	for(int i=1;i<=mid;++i){
		a=sum(1,mid,i);
		if(a==b){
			++ans;
			flag=2;
			break;
		}
	}
	string aa="",bb="";
	for(int i=0;i<mid;++i) aa.push_back(s[i]),bb.push_back(s[i+mid]);
	if(ans==0) cout<<"NOT POSSIBLE"<<endl;
	else if(ans==1||aa==bb){
		if(flag==1) cout<<aa<<endl;
		else cout<<bb<<endl;
	}
	else cout<<"NOT UNIQUE"<<endl;
	return 0;
}
