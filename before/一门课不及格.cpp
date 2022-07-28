#include<iostream>
using namespace std;
int main()
{
	int yw,sx;
	cin>>yw>>sx;
	if(yw<60&&sx>=60) cout<<"1";
	else if(sx<60&&yw>=60) cout<<"1";
	else cout<<"0";
	return 0;
}

