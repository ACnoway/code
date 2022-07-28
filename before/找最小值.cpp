#include<iostream>
using namespace std;
int main()
{
	int n,s=0;
	cin>>n;
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		if(s>=a) s=a;
	}
	cout<<s;
	return 0;
}

