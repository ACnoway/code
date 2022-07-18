#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
	double m,h,bmi;
	cin>>m>>h;
	bmi=m/(h*h);
	if(bmi<18.5) printf("Underweight");
	else if(18.5<=bmi&&bmi<24.0) printf("Normal");
	else if(24.0<=bmi) printf("%lf\nOverweight",bmi);
	return 0;
}
