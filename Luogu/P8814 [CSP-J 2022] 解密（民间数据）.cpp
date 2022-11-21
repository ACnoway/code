#include<iostream>
#include<cmath>
#define int long long
using namespace std;
int m,n,d,e,kai,t;
signed main()
{
	cin>>t;
	while(t--){
		cin>>n>>d>>e;
		m=n-d*e+2;
		kai=m*m-4*n;
		if(kai<0||(int)sqrt(kai)*(int)sqrt(kai)!=kai){
			cout<<"NO"<<endl;
			continue;
		}
		kai=sqrt(kai);
		if((m+kai)%2==1||m<=kai){
			cout<<"NO"<<endl;
			continue;
		}
		cout<<((m-kai)>>1)<<' '<<((m+kai)>>1)<<endl;
	}
	return 0;
}
