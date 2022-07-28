#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int a[21];
int main()
{
	int n;
	cin>>n;
	a[1]=1;
	for(int i=2;i<=n;i++){
		a[i]=(a[i-1]+1)*2;
	}
	cout<<a[n];
	return 0;
}

