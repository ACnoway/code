#include<cstdio>
#include<cmath> 
int main()
{
	const double PI=3.14159;
	int h,r,n;
	double V;
	scanf("%d%d",&h,&r);
	V=PI*r*r*h;
	n=ceil(20/(V/1000));
	printf("%d",n);
	return 0;
} 
