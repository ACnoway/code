#include<iostream>
using namespace std;
int main()
{
	int y;
	long x;
	cin>>x>>y;
	if(y>=0) 
	{
		if(x<y) cout<<"<";
		if(x==y) cout<<"=";
		if(x>y) cout<<">";
	}
	if(y<0) cout<<">";
	return 0;
}
