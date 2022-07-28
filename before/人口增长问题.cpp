#include<iostream>
#include<iomanip> 
using namespace std;
int main()
{
	double x;
	int n;
	cin>>x>>n;
	for(int i=0;i<n;i++){
		x*=1.001;
	} 
	cout<<fixed<<setprecision(4)<<x;
	return 0;
}

