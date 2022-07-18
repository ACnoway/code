#include<cstdio>
using namespace std;
int main()
{
	const double pi=3.14159;
	double r;
	scanf("%lf",&r);
	double d=2*r,z=2*pi*r,s=pi*r*r;
	printf("%.4lf %.4lf %.4lf",d,z,s);
	return 0;
} 
