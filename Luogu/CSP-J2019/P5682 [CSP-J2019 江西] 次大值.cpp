#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
long long a[200005],b[200005];
int main(){
	int n,tail=0;
	long long maxx=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i==j) continue;
			bool flag=true;
			for(int t=1;t<=tail;t++){
				if(b[t]==a[i]%a[j]){
					flag=false;
					break;
				}
			} 
			if(flag){
				b[++tail]=a[i]%a[j];
				maxx=max(a[i]%a[j],maxx);
			}
		}
	}
	long long m2=0;
	for(int i=1;i<=tail;i++){
		if(b[i]>m2&&b[i]<maxx) m2=b[i];
	}
	cout<<m2;
	return 0;
}




