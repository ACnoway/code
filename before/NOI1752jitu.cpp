#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
	int n;
	cin>>n;
	if(n&1){
		cout<<"0 0"; return 0;
	}
	if(n%4==0){
		cout<<n/4;
	}
	else if(n>4){
		int temp=n/4,temp1=n;
		temp1%=4; temp+=temp1/2;
		cout<<temp;
	}
	else{
		cout<<"1 1"; return 0;
	}
	cout<<" "<<n/2;
	return 0;
}
