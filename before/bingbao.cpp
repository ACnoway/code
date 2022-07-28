#include<iostream>
using namespace std;
int a[1001];
int main(){
	int n,b=0;
	cin>>n;
	a[b++]=n;
	while(n!=1){
		if(n%2==0){
			n/=2;
		}
		else{
			n=n*3+1;
		}
		a[b++]=n;
	}
	for(int i=b-1;i>0;i--){
		cout<<a[i]<<" ";
	}
	cout<<a[0];
	return 0;
}

