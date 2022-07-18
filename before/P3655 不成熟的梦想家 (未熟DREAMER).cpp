#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
long long cg[200002];
int main()
{
	int n,q,s,t;
	cin>>n>>q>>s>>t;
	for(int i=0;i<=n;i++){
		cin>>cg[i];
	}
	long long b=0;
	for(int i=0;i<q;i++){
		int x,y,z;
		cin>>x>>y>>z;
		for(int j=x;j<=y&&j<=n;j++){
			cg[j]+=z;
		}
		for(int j=1;j<=n;j++){
			if(cg[i-1]<cg[i]){
				b=b-s*abs(cg[i-1]-cg[i]);
			}
			else if(cg[i-1]>cg[i]){
				b=b+t*abs(cg[i-1]-cg[i]);
			}
		}
		cout<<b<<endl;
		
	}
	return 0;
}
