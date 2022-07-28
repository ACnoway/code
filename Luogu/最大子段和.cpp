#include<iostream>
#include<cmath>
using namespace std;
int a[200005];
long long f[200005];
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		f[i]=a[i];
	}
	for(int i=n-1;i>=1;i--){
		f[i]=max(f[i],f[i+1]+a[i]);
	}
	long long ans=-999999;
	for(int i=1;i<=n;i++){
		ans=max(ans,f[i]);
	}
	cout<<ans<<endl;
	return 0;
}
