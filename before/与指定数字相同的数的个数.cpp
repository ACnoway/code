#include<iostream>
using namespace std;
int main()
{
	int n,m,b=0;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		if(a==m) b+=1;
	}
	cout<<b;
	return 0;
}


