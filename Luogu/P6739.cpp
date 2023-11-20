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
typedef unsigned long long ll;
const int N=2000006;
const ll base=131;
int n;
string s;
ll pre[N],LG[N];
inline ll qujian(int l,int r){
	return pre[r]-pre[l-1]*LG[r-l+1];
}
inline ll shan(int l,int r,int k){
	return qujian(l,k-1)*LG[r-k]+qujian(k+1,r);
}
int main()
{
	cin>>n>>s;
	if(!(n&1)){
		cout<<"NOT POSSIBLE"<<endl;
		return 0;
	}
	LG[0]=1;
	for(int i=1;i<=n;++i){
		LG[i]=LG[i-1]*base;
		pre[i]=pre[i-1]*base+(s[i-1]-'A'+1);
	}
	string aa,bb;
	ll a,b;
	int ans=0,mid=(n+1)>>1,flag=0;
	a=qujian(1,mid-1);
	for(int i=1;i<mid;++i) aa.push_back(s[i-1]);
	for(int i=mid;i<=n;++i){
		b=shan(mid,n,i);
		if(a==b){
			++ans;
			flag=1;
			break;
		}
	}
	b=qujian(mid+1,n);
	for(int i=mid+1;i<=n;++i) bb.push_back(s[i-1]);
	for(int i=1;i<=mid;++i){
		a=shan(1,mid,i);
		if(a==b){
			++ans;
			flag=2;
			break;
		}
	}
	if(ans==0) cout<<"NOT POSSIBLE"<<endl;
	else if(ans==1||aa==bb){
		if(flag==1) cout<<aa<<endl;
		else cout<<bb<<endl;
	}
	else cout<<"NOT UNIQUE"<<endl;
	return 0;
}
