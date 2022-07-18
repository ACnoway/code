#include<iostream>
#include<cstdio>
using namespace std;
int a[30][2];
long long f[30005];
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int v,p;
		cin>>v>>p;
		a[i][0]=v*p;
		a[i][1]=v;
	}
	for(int i=1;i<=m;i++){
    	for(int c=n;c>=0;c--){
    	    if(c>=a[i][1])
    		    f[c]=max(f[c],f[c-a[i][1]]+a[i][0]);
    	}
	}
	long long ans=0;
	for(int i=0;i<=n;i++) ans=ans<f[i]?f[i]:ans;
	cout<<ans<<endl;
	return 0;
}




