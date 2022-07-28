#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	float weight;
	char fast;
	cin>>weight;
	cin>>fast;
	if(weight<=1000.0){
		if(fast==110) cout<<"8";
		else cout<<"13";
	}
	else{
		int cz=4*ceil((weight-1000.0)/500);
		if(fast==110) cout<<8+cz;
		else cout<<8+cz+5;
	}
	return 0;
}
