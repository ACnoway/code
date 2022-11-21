#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
	double x;
	cin>>x;
	if(x>=90) cout<<"4.0"<<endl;
	else if(x>=60) printf("%.1lf",4.0-(90-x)/10);
	else{
		x=floor(sqrt(x)*10.0);
		
	}
	return 0;
}
