#include <bits/stdc++.h>
#define debug_(x) cerr << #x << " = " << x << ' '
#define debug(x) cerr << #x << " = " << x << '\n'

using namespace std;

typedef long long ll;
int cs,n,p;
double f[50004];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int T,w,sum;
	double v;
	cin >> T;
	cs=T;
	while(T--) {
		cin>>n>>p;
		sum=0;
		for(int i=0;i<=50000;++i) f[i]=-1;
		f[0]=0;
		for(int i=1;i<=n;++i){
			int x,y;
			cin>>x>>y;
			sum+=x+x+y+y;
			w=min(x,y)*2;
			v=sqrt(x*x+y*y)*2.0;
			for(int j=50000;j>=w;--j){
				if(f[j-w]>=0) f[j]=max(f[j],f[j-w]+v);
			}
		}
		double ans=0;
		p-=sum;
		for(int i=0;i<=min(50000,p);++i){
			if(f[i]>=0) ans=max(ans,min((double)p,f[i]));
		}
		cout<<fixed<<setprecision(7)<<"Case #"<<cs-T<<": "<<ans+sum<<endl;
	}
	
	return 0;
}