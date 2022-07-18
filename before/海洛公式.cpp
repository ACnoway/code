#include<cstdio>
#include<cmath>
int main()
{
	double a,b,c,s;
	scanf("%lf%lf%lf",&a,&b,&c);
	double p=1/2.0*(a+b+c);
	s=sqrt(p*(p-a)*(p-b)*(p-c));
	printf("%.1lf",s);
	return 0;
}
