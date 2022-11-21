#include<iostream>
using namespace std;
int main()
{
	int n,v,m,a,now,ans=0;
	cin>>n>>v>>m>>a;
	now=v;
	for(int i=1;i<=n;++i){
		ans+=now;
		if(i%m==0) now+=a;
	}
	cout<<ans<<endl;
	return 0;
}
