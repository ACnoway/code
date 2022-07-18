#include<iostream>
#include<cmath>
using namespace std;
int a[3002]={0},b[3001]={0};
int main()
{
	int n,c,add=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		b[i]=abs(a[i]-a[i+1]);
		cout<<b[i]<<" ";
	}
	cout<<endl<<endl;
	cout<<endl;
	for(int i=n-1;i>0;i--){
		if(b[i-1]==i) add++;
		cout<<b[i-1]<<" ";
	}
	cout<<add;
	if(add==n-1) cout<<"Jolly";
	else cout<<"Not Jolly";
	return 0;
}

