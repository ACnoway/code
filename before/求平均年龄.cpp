#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	int b;
	float aver=0;
	cin>>b;
	for(int i=0;i<b;i++){
		int a;
		cin>>a;
		aver+=a;
	}
	aver=aver/b;
	cout<<fixed<<setprecision(2)<<aver;
	return 0;
}


