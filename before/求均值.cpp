#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	int n;
	double aver;
	cin>>n;
	for(int i=0;i<n;i++) {
		double a;
		cin>>a;
		aver+=a;
	}
	aver/=n;
	cout<<fixed<<setprecision(4)<<aver;
	return 0;
}


