#include<iostream>
using namespace std;
int main()
{
	float juli,bike,walk;
	cin>>juli;
	bike=juli/3.0+27.0+23.0;
	walk=juli/1.2;
	if(bike<walk) cout<<"Bike";
	else if(bike>walk) cout<<"Walk";
	else cout<<"All";
	return 0;
}

