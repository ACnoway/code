#include<iostream>
using namespace std;
int a[101]={0};
int main()
{
	int n;
	cin>>n;
	for(int i=n-1;i>=0;i--){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		cout<<a[i];
		if(i!=n-1) cout<<" ";
	}
	return 0;
}

