#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	float aver=0;
	for(int i=1;i<=12;i++){
		float a;
		cin>>a;
		aver+=a;
	}
	aver=aver/12.0;
	cout<<fixed<<setprecision(2)<<"$"<<aver;
	return 0;
}
