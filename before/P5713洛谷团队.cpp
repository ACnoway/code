#include<iostream>
using namespace std;
int main()
{
	int ti,local,luogu;
	cin>>ti;
	local=ti*5;
	luogu=ti*3+11;
	if(local<luogu) cout<<"Local";
	else cout<<"Luogu";
	return 0;
}

