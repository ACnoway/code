#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
double dis(double x1,double x2,double y1,double y2){
	return sqrt(pow(x2-x1,2)+pow(y2-y1,2));
}
int main()
{
	double x1,x2,x3,y1,y2,y3;
	cin>>x1>>y1>>x2>>y2>>x3>>y3;
	double a=dis(x1,x2,y1,y2),b=dis(x1,x3,y1,y3),c=dis(x2,x3,y2,y3);
	printf("%.2lf",a+b+c);
	return 0;
}

