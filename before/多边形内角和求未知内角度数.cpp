#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int degree=(n-2)*180;
	for(int i=0;i<(n-1);i++){
		int a;
		cin>>a;
		degree-=a;
	}
	cout<<degree;
	return 0;
}


