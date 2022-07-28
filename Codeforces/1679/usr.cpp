#include<cstdio>
#include<cmath>
#include<iostream>
#define belong(x) ((x-1)/sqrtn+1)
#define begin(x) ((x-1)*sqrtn+1)
#define end(x) (x*sqrtn)
using namespace std;
long long a[201005];
bool f[2000];
int rep;
int main(){
	int n,q;
	int sqrtn;
	cin>>n>>q;
	sqrtn=sqrt(n);
	int x,t,r;
	long long ans=0;
	int i;
	for(i=1;i<=n;++i){
		cin>>a[i];
		ans+=a[i];
	}
	while(q--){
		cin>>t;
		if(t==1){
			cin>>r>>x;
			if(f[belong(r)]){
				for(i=begin(belong(r));i<=end(belong(r));++i)a[i]=rep;
				f[belong(r)]=false;
			}
			ans-=a[r];
			ans+=x;
			a[r]=x;
			cout<<ans<<endl;
		}
		else{
			cin>>rep;
			ans=rep*n;
			for(i=1;i<=belong(n);++i)f[i]=true;
			cout<<ans<<endl;
		}
	}
	return 0;
}
