#include<iostream>
#include<cstdio>
using namespace std;
long long a[1000001],b[1000001];
int main()
{
	for(int i=0;i<1000001;i++){
		a[i]=1;
		b[i]=1;
	}
	int t,n,k;
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n>>k;
		if(n==0){
			cout<<"0";
			continue;
		}
		for(int o=0;o<k;o++){
			for(int p=1;p<n;p++){
				for(int u=0;u<p;u++){
					b[p]+=a[u];
				}
			}
			for(int i=0;i<1000001;i++){
				a[i]=b[i];
			}
		}
		printf("%ld\n",b[n-1]%1000000007);
		for(int i=0;i<1000001;i++){
			a[i]=1;
			b[i]=1;
		}
	}
	return 0;
}
