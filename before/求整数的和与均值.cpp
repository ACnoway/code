#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	int n,add;
	float aver;
	cin>>n;
	for(int i=0;i<n;i++) {
		int a;
		cin>>a;
		add+=a;
	}
	cout<<add<<" ";
	aver=(float)add/n;
	cout<<fixed<<setprecision(5)<<aver;
	return 0;
}


