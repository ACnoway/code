#include<iostream>
using namespace std;
int a[101]={0};
int main()
{
	int n,m,b=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	cin>>m;
	for(int i=0;i<n;i++){
		if(a[i]==m) b++;
	}
	cout<<b;
	return 0;
}

