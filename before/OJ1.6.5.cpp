#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	double y,a,b,c,d,all[5]={0};
	double n;
	cin>>n;
	for(double i=0;i<n;i++){
		cin>>y;
		if(y<=18) all[0]++;
		else if(y<=35) all[1]++;
		else if(y<=60) all[2]++;
		else all[3]++;
	}
	a=all[0]/n*100;
	b=all[1]/n*100;
	c=all[2]/n*100;
	d=all[3]/n*100;
	printf("%.2lf%\n%.2lf%\n%.2lf%\n%.2lf%%",a,b,c,d);
	return 0;
}

